#include <bits/stdc++.h>
void func(vector<vector<int>> &powerset,vector<int> &v,vector<int> curset,int i){
    curset.push_back(v[i]);
    powerset.push_back(curset);
    for(int j = i+1;j<v.size();j++) func(powerset,v,curset,j);
} 
vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> powerset;
    vector<int> curset;
    powerset.push_back({});
    for(int i =0;i<v.size();i++) func(powerset,v,curset,i);
    return powerset;
}
