#include<bits/stdc++.h>
using namespace std;
int kthlargest(vector<int> &arr,int l,int r,int k){
	if(l==r) return arr[l];
	int p = l;
	int pivot = arr[r];
	for(int i = l;i<r;i++){
		if(arr[i] < pivot){
			swap(arr[i],arr[p++]);
		}
	}
	swap(arr[r],arr[p]);
	if(p >= k) return kthlargest(arr,l,p-1,k);
	if(p < k-1) return kthlargest(arr,p+1,r,k);
	else return arr[p];
}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{	
	vector<int> ans;
	ans.push_back(kthlargest(arr,0,n-1,k));
	ans.push_back(kthlargest(arr,0,n-1,n-k+1));
	return ans;
}
