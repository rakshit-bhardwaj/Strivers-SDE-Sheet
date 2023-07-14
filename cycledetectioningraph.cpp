#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> v2;
typedef vector<int> v;
typedef unordered_set<int> us;

void func(v2 &graph,us &s,int n,int x,int par,bool &ans){
    if(s.find(x)!=s.end()){
        ans = true;
        return;
    }

    s.insert(x);

    for(auto i : graph[x]){
        if(i!=par) func(graph,s,n,i,x,ans);
    }
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    v2 graph(n+1);
    us s;
    bool ans = false;

    for(auto edge : edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    for(int i =1;i<=n;i++){
        if(s.find(i)!=s.end()) continue;
        func(graph,s,n,i,-1,ans);
        if(ans) return "Yes";
    }

    return "No";
}
