#include <bits/stdc++.h> 

int func(vector<vector<int>> &grid,int x,int y,vector<vector<int>> &dp){
    if(x==grid.size()-1 && y==grid[0].size()-1) return grid[x][y];
    if(dp[x][y]!=-1) return dp[x][y];
    int down = INT_MAX,right = INT_MAX;
    if(x < grid.size()-1) down = func(grid,x+1,y,dp);
    if(y < grid[0].size()-1) right = func(grid,x,y+1,dp);
    return dp[x][y] =  grid[x][y] + min(down,right);
}
int minSumPath(vector<vector<int>> &grid) {
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
    return func(grid,0,0,dp);
}
