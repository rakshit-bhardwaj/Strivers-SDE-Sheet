#include<bits/stdc++.h>
using namespace std;

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    queue<pair<int,int>> q;
    
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]==2) q.push({i,j});
        }
    }
    
    int minutes = 0;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    while(!q.empty()){
        int size = q.size();
        bool foundnone = true;
        while(size--){
            auto cur  = q.front();
            int x = cur.first;
            int y = cur.second;
            q.pop();
            for(int i =0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= n || ny >=m || grid[nx][ny] != 1) continue;
                foundnone = false;
                grid[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
        if(foundnone) break;
        minutes++;
    }
    
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]==1) return -1;
        }
    }
    
    return minutes;
}
