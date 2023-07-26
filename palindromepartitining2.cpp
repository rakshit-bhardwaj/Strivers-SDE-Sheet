#include <bits/stdc++.h>

bool ispalindrome(int i,int j,string &str){
    while(i<j){
        if(str[i]!=str[j]) return false;
        i++;j--;
    }
    return true;
} 

int palindromePartitioning(string str) {
    int n = str.size();
    vector<int> dp(n+1,0);
    for(int i =n-1;i>=0;i--){
        int mincost = 1e9;
        for(int j = i;j<n;j++){
            if(ispalindrome(i,j,str)){
                int cost = 1 + dp[j+1];
                mincost = min(mincost,cost);
            }
        }
        dp[i] = mincost;
    }
    return dp[0]-1;
}
