#include<bits/stdc++.h>
using namespace std;

long func(int *den,int n,int j,int value,vector<vector<long>> &dp){
    if(value==0) return 1;
    if(value < 0) return 0;
    if(dp[value][j]!=-1) return dp[value][j];
    long count =0;
    for(int i =j;i<n;i++){
        count += func(den,n,i,value-den[i],dp);
    }
    return dp[value][j] = count;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(value + 1,vector<long>(n+1,-1));
    return func(denominations,n,0,value,dp);

}
