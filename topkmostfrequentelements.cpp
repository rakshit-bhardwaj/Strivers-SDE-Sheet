#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int,int> frq;
    priority_queue<pair<int,int>> q;
    vector<int> ans;
    for(int i =0;i<arr.size();i++) frq[arr[i]]++;
    for(auto x : frq) q.push({x.second, x.first});
    
    while (k--) {
      ans.push_back(q.top().second);
      q.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}
