#include<bits/stdc++.h>
using namespace std;

int dx[]={-1, -1, -1, 0, 1, 1, 1, 0};
int dy[]={-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(int x,int y,int**arr,int n,int m){
   arr[x][y] = 0;
   for(int i =0;i<8;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == 0) continue;
      dfs(nx,ny,arr,n,m);
   }
}

int getTotalIslands(int** arr, int n, int m)
{
   int count = 0;
   
   for(int i = 0;i<n;i++){
      for(int j = 0;j<m;j++){
         if(arr[i][j]==1){
            count ++;
            dfs(i,j,arr,n,m);
         }
      }
   }
   return count;
}
