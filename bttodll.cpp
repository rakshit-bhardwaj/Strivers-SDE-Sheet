typedef BinaryTreeNode<int>* bt;
bt prevn = NULL,head = NULL;

void func(bt root){
    if(root==NULL) return;
    
    func(root->left);
    if(prevn == NULL) head = root;
    else {
        root->left = prevn;
        prevn->right = root;
    }
    prevn = root;
    func(root->right);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    prevn = NULL;
    head = NULL;
    func(root);
    return head;    
}
