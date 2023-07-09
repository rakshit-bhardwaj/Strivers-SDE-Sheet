int getMaxWidth(TreeNode<int> *root)
{
    if(root == NULL) return 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    int ans = 0;
    while(!q.empty()){
        int size = q.size();
        ans = max(ans,size);
        while(size--){
            auto cur = q.front();
            q.pop();
            if(cur->left!=NULL) q.push(cur->left);
            if(cur->right!=NULL) q.push(cur->right);
        }
    }
    return ans;
}
