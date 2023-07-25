#include <bits/stdc++.h> 

int func(vector<int> &arr, int i ,int j,vector<vector<int>> &dp){
    if(i==j) return dp[i][j] = 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini = 1e9;

    for(int k = i;k<j;k++){
        int steps = (arr[i-1] * arr[k] * arr[j]) + func(arr,i,k,dp) + func(arr,k+1,j,dp);
        mini = min(mini,steps);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N,vector<int>(N,-1));
    return func(arr,1,N-1,dp);
}

