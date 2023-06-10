void preorder(BinaryTreeNode<int>* root,vector<int> &path){
    if(root==NULL) return;
    path.push_back(root->data);
    preorder(root->left,path);
    preorder(root->right,path);
}

void inorder(BinaryTreeNode<int>* root,vector<int> &path){
    if(root==NULL) return;
    inorder(root->left,path);
    path.push_back(root->data);
    inorder(root->right,path);
}

void postorder(BinaryTreeNode<int>* root,vector<int> &path){
    if(root==NULL) return;
    postorder(root->left,path);
    postorder(root->right,path);
    path.push_back(root->data);

}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<int> v1,v2,v3;
    preorder(root,v1);
    inorder(root,v2);
    postorder(root,v3);
    vector<vector<int>> ans = {v2,v1,v3};
    return ans;
}
