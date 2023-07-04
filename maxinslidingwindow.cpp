#include <bits/stdc++.h> 
using namespace std;

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    priority_queue<pair<int,int>> q;
    vector<int> ans;

    for(int i =0;i<nums.size();i++){
        q.push({nums[i],i});
        if(i>k-2){
            while(q.top().second < i + 1 -k) q.pop();
            ans.push_back(q.top().first);
        }
    }
    return ans;
}
