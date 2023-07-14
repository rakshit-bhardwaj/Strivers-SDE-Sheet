typedef BinaryTreeNode<int> * t;

int func(t root){
    if(root==NULL) return 0;

    int l = 0,r = 0;
    if(root->left != NULL) l = root->left->data;
    if(root->right !=NULL) r = root->right->data;
    if(l + r > root->data) root->data = l + r;
    else {
        if(root->left != NULL) root->left->data = root->data;
        if(root->right != NULL) root->right->data = root->data;
    }

    l = func(root->left);
    r = func(root->right);

    if(l + r != 0) root->data = l + r;

    return root->data;
}

void changeTree(BinaryTreeNode < int > * root) {
    func(root);
} 
