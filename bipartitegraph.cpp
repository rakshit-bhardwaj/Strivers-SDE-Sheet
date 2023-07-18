#include<bits/stdc++.h>
using namespace std;
typedef vector<int> v1;
typedef vector<v1> v2;

bool func(v2 &graph,v1 &cols,int x,int prev){
	cols[x] = !prev;
	for(auto n : graph[x]){
		if(cols[n] == cols[x]) return false;
		if(cols[n] == -1) if(func(graph,cols,n,cols[x]) == false) return false; 
	}
	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n = edges.size();

	v2 graph(n);
	v1 cols(n,-1);

	for(int i =0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(edges[i][j]==1){
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	for(int i = 0;i<n; i++)
		if(cols[i]==-1 && func(graph,cols,i,1) == false) 
			return false;
			
	return true;
}
