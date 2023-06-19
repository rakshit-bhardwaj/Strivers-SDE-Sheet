#include <bits/stdc++.h> 

void solve(vector<int> &arr,int n,vector<vector<int>> &ans,vector<int> cur,int ind){
    ans.push_back(cur);
    for(int i=ind;i<n;i++){
        if(i!=ind && arr[i] == arr[i-1]) continue;
        cur.push_back(arr[i]);
        solve(arr,n,ans,cur,i+1);
        cur.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> cur;
    solve(arr,n,ans,cur,0);
    return ans;
}
