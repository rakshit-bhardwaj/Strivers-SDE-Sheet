void solve(TreeNode<int> *node,int &k,int &ans){
    if(node==NULL) return;
    solve(node->right,k,ans);
    k--;
    if(!k){
        ans = node->data;
        return;
    }
    solve(node->left,k,ans);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans = -1;
    solve(root,k,ans);
    return ans;
}
