#include<bits/stdc++.h>
using namespace std;

typedef vector<long long> v;
typedef vector<v> v2;

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    const long long INF = 1000000000;
    v2 graph(n+1,v(n+1,INF));

    for(auto edge : edges) graph[edge[0]][edge[1]] = edge[2];
    for(int i=0;i<=n;i++) graph[i][i] = 0;
    for(int i =1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(graph[j][i] == INF || graph[i][k] == INF) continue;
                if(graph[j][k] > graph[j][i] + graph[i][k]) graph[j][k] = graph[j][i] + graph[i][k];
            }
        }
    }

    return graph[src][dest];

}
