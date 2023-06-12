bool search(BinaryTreeNode<int>*node,int x){
    if(node==NULL) return false;
    if(node->data == x) return true;

    if(node->data > x) return search(node->left,x);
    else return search(node->right,x);
}
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    return search(root,x);
}
