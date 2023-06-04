#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> triangle;
  triangle.push_back({1});
  if(n==1) return triangle;
  for(int i =1;i<n;i++){
    vector<long long int> row;
    row.push_back(1);
    for(int j = 0;j<i - 1;j++){
      row.push_back(triangle[i-1][j] + triangle[i-1][j+1]);
    }
    row.push_back(1);
    triangle.push_back(row);
  }
  return triangle;
}
