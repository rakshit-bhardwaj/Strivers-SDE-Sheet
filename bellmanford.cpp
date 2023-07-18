typedef vector<int> v1;
typedef vector<v1> v2;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    v1 dist(n+1,1e9);
    dist[src] = 0;
    for(int i =0;i<n-1;i++){
        for(auto edge : edges){
            if(dist[edge[0]] == 1e9) continue;
            if(dist[edge[0]] + edge[2] < dist[edge[1]]){
                dist[edge[1]] = dist[edge[0]] + edge[2];
            }
        }
    }
    return dist[dest];
}
