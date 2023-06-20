#include<bits/stdc++.h>

void solve(vector<int> &arr,vector<vector<int>> &ans,vector<int> &cur,int ind,int cursum,int k){
    if(ind == arr.size()){
        if(cursum == k) ans.push_back(cur);
        return;
    }
    solve(arr,ans,cur,ind+1,cursum,k);
    cur.push_back(arr[ind]);
    solve(arr,ans,cur,ind+1,cursum + arr[ind],k);
    cur.pop_back();
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{ 
    vector<vector<int>> ans;
    vector<int> cur;
    int cursum = 0;
    if(k==0) ans.push_back({});
    solve(arr,ans,cur,0,0,k);
    return ans;
}
