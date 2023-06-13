#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<vector<int>> graph(vertex,vector<int>(vertex,0));
    vector<int> ans;
    unordered_map<int,int> visited;
    queue<int> q;

    for(int i =0;i<edges.size();i++){
        graph[edges[i].first][edges[i].second]=1;
        graph[edges[i].second][edges[i].first]=1;
    }
    
    q.push(0);
    visited[0] = 1;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(int i = 0;i<vertex;i++){
                if(graph[cur][i] == 1 && visited.find(i)==visited.end()){
                    visited[i] = 1;
                    q.push(i);
                }
            }

        }
    }
    for(int i =1;i<vertex;i++) if(visited.find(i)==visited.end()) ans.push_back(i);
    return ans;
}
