#include <bits/stdc++.h> 
int nx[4] = {0, 0, -1, 1};
int ny[4] = {1, -1, 0, 0};

void bfs(vector<vector<int>> &maze,vector<vector<int>> &ans,vector<vector<int>> vis, int x,int y){
  vis[x][y] = 1;
  if (x == maze.size()-1 && y == maze[0].size()-1) {
    vector<int> temp;
    for(int i =0;i<maze.size();i++){
      for(int j = 0;j<maze.size();j++){
        temp.push_back(vis[i][j]);
      }
    }
    ans.push_back(temp);
    return;
  }
  for(int i =0;i<4;i++){
    int dx = x + nx[i];
    int dy = y + ny[i];
    if(dx < 0 || dx >= maze.size() || dy<0 || dy>=maze[0].size() || vis[dx][dy] == 1 || maze[dx][dy] == 0) continue;
    bfs(maze,ans,vis,dx,dy);
  }

}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>> vis(maze.size(),vector<int>(maze.size(),0));
  vector<vector<int>> ans;
  if(maze[0][0]==0) return ans;
  bfs(maze,ans,vis,0,0); 
  return ans;
}
