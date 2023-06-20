#include<bits/stdc++.h>

void solve(vector<int> &arr,int n,vector<vector<int>> &ans,vector<int> cur,int ind,int cursum,int k){
	if(cursum == k){
		ans.push_back(cur);
	}
    for(int i=ind;i<n;i++){
        if(i!=ind && arr[i] == arr[i-1]) continue;
        cur.push_back(arr[i]);
        solve(arr,n,ans,cur,i+1,cursum + arr[i],k);
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int k)
{
	sort(arr.begin(),arr.end());
	vector<vector<int>> ans;
    vector<int> cur;
    int cursum = 0;
    solve(arr,n,ans,cur,0,0,k);
	return ans;
}
