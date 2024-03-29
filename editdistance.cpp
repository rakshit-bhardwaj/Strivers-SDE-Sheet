int editDistance(string str1, string str2)
{
    vector<vector<int>> dp(str1.size()+1,vector<int>(str2.size()+1,0));
        for(int i = 0;i<=str1.size();i++) dp[i][0] = i;
        for(int j = 0;j<=str2.size();j++) dp[0][j] = j;

        for(int i = 1;i<=str1.size();i++){
            for(int j = 1;j<=str2.size();j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + dp[i-1][j];
                    dp[i][j] = min(dp[i][j],1 + dp[i][j-1]);
                    dp[i][j] = min(dp[i][j],1 + dp[i-1][j-1]);
                }
            }
        }
        return dp[str1.size()][str2.size()];
}
