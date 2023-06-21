#include<bits/stdc++.h>
using namespace std;

bool check(int matrix[9][9],int x,int y){
    for(int i =0;i<9;i++){
        if(i!=x && matrix[i][y] == matrix[x][y]) return false;
        if(i!=y && matrix[x][i] == matrix[x][y]) return false;
    }

    int xblock = (x/3) * 3, yblock = (y/3) * 3;
    
    for(int i =xblock;i<xblock + 3;i++){
        for(int j = yblock;j<yblock + 3;j++){
            if(i==x && j ==y) continue;
            if(matrix[i][j] == matrix[x][y]) return false;
        }
    }
    return true;
}

bool solve(int matrix[9][9],vector<pair<int,int>> &req,int ind){
    if(ind == req.size()) return true;
    int x = req[ind].first;
    int y = req[ind].second;
    
    for(int i =1;i<=9;i++){
        matrix[x][y] = i;
        if(check(matrix,x,y)){
            if(solve(matrix,req,ind+1)) return true;
        }   
    }
    matrix[x][y] = 0;
    return false;
}

bool isItSudoku(int matrix[9][9]) {
    vector<pair<int,int>> req;
    for(int i =0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(matrix[i][j]==0)
            req.push_back({i,j});
        }
    }
    
    return solve(matrix,req,0);
}
