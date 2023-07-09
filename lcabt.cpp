TreeNode<int>* func(TreeNode<int> *root,int x,int y){
    if(root==NULL || root->data == x || root->data == y) return root;

    TreeNode<int> *left= func(root->left,x,y);
    TreeNode<int> *right = func(root->right,x,y);

    if(left != NULL && right != NULL) return root;
    if(left != NULL) return left;
    if(right != NULL) return right;
    else return NULL;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	return func(root,x,y)->data;
}
