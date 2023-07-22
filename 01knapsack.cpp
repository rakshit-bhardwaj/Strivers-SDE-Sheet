int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n,vector<int>(w+1,0));
	for(int wt = weights[0];wt<=w;wt++) dp[0][wt] = values[0];
	
	for(int i = 1;i<n;i++){
		for(int wt = 0;wt<=w;wt++){
			int nottake = dp[i-1][wt];
			int take = INT_MIN;
			if(weights[i] <= wt){
				take = values[i] + dp[i-1][wt - weights[i]];
			}
			dp[i][wt] = max(take,nottake);
		}
	}
	return dp[n-1][w];
}
