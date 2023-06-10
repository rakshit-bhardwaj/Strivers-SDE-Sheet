void postorder(TreeNode* root,vector<int> &path){
    if(root==NULL) return;
    postorder(root->left,path);
    postorder(root->right,path);
    path.push_back(root->data);

}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> path;
    postorder(root,path);
    return path;
}


