graphNode* dfs(graphNode *node,unordered_map<graphNode*,graphNode*> &m){
	if(m.find(node)==m.end()){
		graphNode* n = new graphNode(node->data);
		m[node] = n;
	}
	graphNode* cur = m[node];
	for(int i =0;i<node->neighbours.size();i++){
		graphNode* neighbour;
		if(m.find(node->neighbours[i])!=m.end()) neighbour = m[node->neighbours[i]];
		else neighbour = dfs(node->neighbours[i],m);
		cur->neighbours.push_back(neighbour);
	}
	return cur;
}

graphNode *cloneGraph(graphNode *node)
{
    unordered_map<graphNode*,graphNode*> m;
	return dfs(node,m);

}
