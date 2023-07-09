void dfs(TreeNode<int> *node,int x,vector<int> curpath,vector<int> &ans){
	curpath.push_back(node->data);
	if(node->data == x) {
		ans = curpath;
		return;
	} 
	if(node->left!=NULL) dfs(node->left,x,curpath,ans);
	if(node->right!=NULL) dfs(node->right,x,curpath,ans);
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> curpath,ans;
	dfs(root,x,curpath,ans);
	return ans;
}
