void solve(BinaryTreeNode<int> *node,int x,int &ans){
    if(node==NULL) return;
    if(node->data >= x && node->data < ans) ans = node->data; 
    if(node->data > x) solve(node->left,x,ans);
    else solve(node->right,x,ans);
}
int findCeil(BinaryTreeNode<int> *node, int x){
    int ans = INT_MAX;
    solve(node,x,ans);
    return ans == INT_MAX ? -1 : ans;
}
