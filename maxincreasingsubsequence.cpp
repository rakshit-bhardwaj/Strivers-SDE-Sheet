#include <bits/stdc++.h> 
using namespace std;

int func(vector<int> &rack,int i,int lp,vector<vector<int>> &dp){
	if(i == rack.size()+1) return 0;
	if(dp[i][lp]!=-1) return dp[i][lp];
	int cur = func(rack,i+1,lp,dp);
	if(lp==0 || rack[i-1] > rack[lp-1]) cur = max(cur,rack[i-1] + func(rack,i+1,i,dp));
	return dp[i][lp] = cur;
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	return func(rack,1,0,dp);
}
