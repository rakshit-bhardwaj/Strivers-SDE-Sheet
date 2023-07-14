#include<bits/stdc++.h>
using namespace std;

typedef vector<int> v;
typedef vector<v> v2;

void dfs(v2 &graph,v &vis,v &pathvis,int x,bool &ans){
  pathvis[x] = 1;
  vis[x] = 1;
  for (auto n : graph[x]) {
    if(pathvis[n]){
      ans = true;
      return;
    }
    if(vis[n]) continue;
    dfs(graph, vis, pathvis, n, ans);
  }
  pathvis[x] = 0;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  v2 graph(n+1);
  v vis(n+1,0);
  v pathvis(n+1,0);

  bool ans = false;
  for(auto edge : edges) graph[edge.first].push_back(edge.second);
  
  for(int i =1;i<=n;i++){
    if(vis[i]) continue;
    dfs(graph,vis,pathvis,i,ans);
    if(ans) return 1;
  }

  return 0;
}
