vector<int> dijkstra(vector<vector<int>>& vec, int vertices, int edges, int source) {
    vector<vector<pair<int, int>>> graph(vertices);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    for (auto edge : vec) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    q.push({0, source});
    vector<int> dis(vertices, INT_MAX);

    while (!q.empty()) {
        auto cur = q.top();
        q.pop();

        if (cur.first > dis[cur.second])
            continue;

        dis[cur.second] = cur.first;

        for (auto neighbor : graph[cur.second]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (cur.first + weight < dis[v]) {
                q.push({cur.first + weight, v});
            }
        }
    }

    return dis;
}
