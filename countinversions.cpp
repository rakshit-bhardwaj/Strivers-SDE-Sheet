#include <bits/stdc++.h>

long long merge(long long *arr,int n,int l,int m,int r){
    int k = l;
    int i = l;
    int j = m;
    int temp[n];
    long long invcount = 0;
    while(i<m && j<=r){
        if(arr[i]<=arr[j]) temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            invcount += m - i;
        }
    }

    while(i<m) temp[k++] = arr[i++];
    while(j<=r) temp[k++] = arr[j++];

    for(int i =l;i<=r;i++) arr[i] = temp[i];

    return invcount;
}
long long mergesort(long long *arr,int n,int l,int r){
    int mid;
    long long invcount =0;
    if(r>l){
        mid = (r+l)/2;

        invcount+= mergesort(arr,n,l,mid);
        invcount+= mergesort(arr,n,mid+1,r);

        invcount += merge(arr,n,l,mid+1,r);
    }

    return invcount;
}
long long getInversions(long long *arr, int n){
    
    return mergesort(arr,n,0,n-1);
}
