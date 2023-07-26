#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[],
             stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }

void dfs3(int node, vector<int> &vis, vector<int> adjT[],vector<int> &comp) {
        vis[node] = 1;
        comp.push_back(node);
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT,comp);
            }
        }
    }
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n],adjT[n];
    vector<vector<int>> ans;
    for(auto edge: edges){
        adj[edge[0]].push_back(edge[1]);
        adjT[edge[1]].push_back(edge[0]);
    }
    
    vector<int> vis(n,0);
    stack<int> st;
    for(int i =0;i<n;i++){
        if(!vis[i]) dfs(i,vis,adj,st);
    }
    fill(vis.begin(),vis.end(),0);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            vector<int> comp;
            dfs3(node,vis,adjT,comp);
            ans.push_back(comp);
        }
    }
    return ans;
}
