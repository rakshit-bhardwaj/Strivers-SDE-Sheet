#include <bits/stdc++.h> 
int merge(vector<int> &arr,int n,int l,int m,int r){
    int k = l;
    int i = l;
    int j = m;
    int temp[n];
	int c =0,y=m,tot=0;
	for(int z = l;z<m;z++){
		while(y<=r && arr[z] > 2 * arr[y]){
			y++;
			c++;
		}
		tot += c;
	}
    while(i<m && j<=r){
        if(arr[i]<=arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];   
    }

    while(i<m) temp[k++] = arr[i++];
    while(j<=r) temp[k++] = arr[j++];

    for(int i =l;i<=r;i++) arr[i] = temp[i];

    return tot;
}
int mergesort(vector<int> &arr,int n,int l,int r){
    int mid;
    int invcount =0;
    if(r>l){
        mid = (r+l)/2;

        invcount+= mergesort(arr,n,l,mid);
        invcount+= mergesort(arr,n,mid+1,r);

        invcount += merge(arr,n,l,mid+1,r);
    }

    return invcount;
}
int reversePairs(vector<int> &arr, int n){
	return mergesort(arr,n,0,n-1);
}
