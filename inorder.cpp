void inorder(TreeNode *root,vector<int> &path){
    if(root==NULL) return;
    inorder(root->left,path);
    path.push_back(root->data);
    inorder(root->right,path);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> path;
    inorder(root,path);
    return path;
    
}
