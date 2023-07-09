bool comparf(BinaryTreeNode<int> *root1,BinaryTreeNode<int>* root2){
    if((root1 != NULL && root2==NULL) || (root1 == NULL && root2!=NULL)) return false;
    if(root1 == NULL && root2 == NULL) return true;

    if(root1->data != root2->data) return false;
    return comparf(root1->left,root2->left) && comparf(root1->right,root2->right);
}

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    return comparf(root1,root2);
}
