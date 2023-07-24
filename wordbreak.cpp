#include <bits/stdc++.h> 
int func(int i,string &target,unordered_set<string> &st,vector<int> &dp){
    if(i==target.size()) return 1;
    if(dp[i]!=-1) return dp[i];
    string temp;
    for(int j = i;j<target.size();j++){
        temp += target[j];
        if(st.find(temp)!=st.end()){
            if(func(j+1,target,st,dp)) return dp[i] = 1;
        }
    }
    return dp[i] = 0;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    vector<int> dp(target.size()+1,-1);
    unordered_set<string> st(arr.begin(),arr.end());
    return func(0,target,st,dp);
}
