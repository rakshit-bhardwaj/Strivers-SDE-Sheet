void inorder(TreeNode<int> *root,int x,int &ans){
    if(root==NULL) return;
    inorder(root->left,x,ans);
    if(root->val > x) return;
    ans = max(ans,root->val);
    inorder(root->right,x,ans);
}
int floorInBST(TreeNode<int> * root, int X)
{
    int ans=0;
    inorder(root,X,ans);
    return ans;
}
