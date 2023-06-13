void inorder(BinaryTreeNode<int>* node, int key,pair<int,int> &ans){
    if(node==NULL) return;

    inorder(node->left,key,ans);

    if(node->data < key) ans.first = node->data;
    if(node->data > key && ans.second == -1) ans.second = node->data;

    inorder(node->right,key,ans);
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    pair<int,int> ans = {-1,-1};
    inorder(root,key,ans);
    return ans;
}
