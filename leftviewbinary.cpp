vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    if(root==NULL) return ans;
    vector<int> map(3000,-1);
    queue<TreeNode<int>*> q;
    q.push(root);
    int lvl =0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            auto cur = q.front();
            q.pop();
            if(map[lvl] == -1){
                map[lvl] = cur->data;
            }
            if(cur->left!=NULL) q.push(cur->left);
            if(cur->right!=NULL) q.push(cur->right);
        }
        lvl++;
    }
    int i =0;
    while(lvl--) ans.push_back(map[i++]);
    return ans;
}
