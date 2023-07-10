#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> &cur,vector<vector<int>> &graph,unordered_map<int,int> &m,int x){
    m[x] = 1;
    cur.push_back(x);
    for(int i =0;i<graph.size();i++){
        if(graph[x][i] == 1 && m[i] == 0) {
            dfs(cur,graph,m,i);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(V,vector<int>(V,0)),ans;
    unordered_map<int,int> m;
    for(auto edge : edges){
        graph[edge[0]][edge[1]] = 1;
        graph[edge[1]][edge[0]] = 1;
    }

    for(int i =0;i<V;i++){
        if(m[i]==1) continue;
        vector<int> comp;
        dfs(comp,graph,m,i);
        sort(comp.begin(),comp.end());
        ans.push_back(comp);
    }
    return ans;
}
