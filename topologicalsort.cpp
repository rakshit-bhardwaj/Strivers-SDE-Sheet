typedef vector<int> v1;
typedef vector<v1> v2;

void dfs(v2 &graph,int x,v1 &vis,stack<int> &s){
    vis[x] = 1;
    for(auto n : graph[x]){
        if(!vis[n]) dfs(graph,n,vis,s);
    }
    s.push(x);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    v2 graph(v);
    v1 vis(v,0),ans;
    stack<int> s;

    for(auto edge : edges) graph[edge[0]].push_back(edge[1]);
    
    for(int i =0;i<v;i++){
        if(!vis[i]) dfs(graph,i,vis,s);
    }

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
}
