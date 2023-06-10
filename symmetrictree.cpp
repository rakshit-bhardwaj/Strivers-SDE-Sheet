bool func(BinaryTreeNode<int>* left,BinaryTreeNode<int>* right){
    if(left == NULL || right == NULL) return left == right;
    if(left->data!=right->data) return false;

    return func(left->left,right->right) && func(left->right,right->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    return root==NULL || func(root->left,root->right);
}
