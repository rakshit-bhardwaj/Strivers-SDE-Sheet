#include <bits/stdc++.h> 
using namespace std;

void func(vector<int> &num,vector<int> &ans,int cur,int i){
    if(i>=num.size()) return;
    func(num,ans,cur,i+1);
    cur += num[i];
    ans.push_back(cur);
    func(num,ans,cur,i+1);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    ans.push_back(0);
    func(num,ans,0,0);
    sort(ans.begin(),ans.end());
    return ans;
}
