#include <bits/stdc++.h> 

bool issafe(vector<vector<int>> &mat,vector<int> &col,int n,int x,int color){
    for(int i =0;i<n;i++){
        if(i!=x && mat[x][i] == 1 && col[i] == color) return false;
    }
    return true;
}

bool solve(vector<vector<int>> &mat,vector<int> &col,int n,int m,int x){
    if(x == n) return true;
    for(int i =1;i<=m;i++){
        if(issafe(mat,col,n,x,i)){
            col[x] = i;
            if(solve(mat,col,n,m,x+1)) return true;
            col[x] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    vector<int> col(n,0);
    if(solve(mat,col,n,m,0)) return "YES";
    else return "NO";
}
