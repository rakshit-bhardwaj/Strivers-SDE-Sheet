TreeNode<int>* func(TreeNode<int> *root,int x,int y){
    if(root==NULL) return NULL;
    if(root->data >= x && root->data <= y) return root;
    if(root->data >= x && root->data >= y) return func(root->left,x,y);
    if(root->data <= x && root->data <=y) return func(root->right,x,y);
}

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	return func(root,min(P->data,Q->data),max(P->data,Q->data));
}
