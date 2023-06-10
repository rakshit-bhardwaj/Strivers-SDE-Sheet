int func(TreeNode<int> *root,int &ans){
    if(root==NULL) return 0;
    int lh = func(root->left,ans);
    int rh = func(root->right,ans);
    ans = max(ans,lh + rh);
    return 1 + max(lh,rh);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	if(root==NULL) return 0;
    int ans =0;
    func(root,ans);
    return ans;
}
