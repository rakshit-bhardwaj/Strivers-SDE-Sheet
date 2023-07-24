#include <bits/stdc++.h> 
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<pair<int, int>, int>> ans;
    vector<vector<pair<int,int>>> graph(n + 1);
    for (auto edge : g){
        graph[edge.first.first].push_back({edge.first.second, edge.second});
        graph[edge.first.second].push_back({edge.first.first, edge.second});
        
    } 

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    q.push({0, 1, -1});
    vector<int> vis(n + 1, 0);
    
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        int node = cur[1];
        int wt = cur[0];
        int par = cur[2];
        if (vis[node]) continue;
        vis[node] = 1;
        if (par != -1) {
            ans.push_back({{node, par}, wt});
        }
        for (auto n : graph[node]) {
            if (!vis[n.first]) q.push({n.second, n.first, node});
        }
    }
    return ans;
}
