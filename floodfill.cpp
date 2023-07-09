#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(vector<vector<int>> &image, int x, int y, int newColor,int col) {
    image[x][y] = newColor;
    for(int i =0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < image.size() && ny < image[0].size() && image[nx][ny] == col) dfs(image,nx,ny,newColor,col);
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{   
    if(image[x][y] == newColor) return image;
    dfs(image,x,y,newColor,image[x][y]);
    return image;
}
