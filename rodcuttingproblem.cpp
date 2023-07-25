int func(vector<int> &price,int n, int x,int cur,vector<vector<int>> &dp){
	if(x == n) return 0;
	if(dp[x][cur]!=-1) return dp[x][cur];
	int nottake = func(price,n,x+1,cur,dp);
	int take = 0;
	if(cur + x + 1 <= n){
		take = price[x] + func(price,n,x,cur + x+1,dp);
	}

	return dp[x][cur] = max(take,nottake);
}
int cutRod(vector<int> &price, int n)
{	
	vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	return func(price,n,0,0,dp);
}
