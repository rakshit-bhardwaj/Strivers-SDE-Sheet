void preorder(TreeNode* root,vector<int> &path){
    if(root==NULL) return;
    path.push_back(root->data);
    preorder(root->left,path);
    preorder(root->right,path);

}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> path;
    preorder(root,path);
    return path;
}
