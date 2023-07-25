int x;
TreeNode<int>* func(vector<int> &preOrder, int ub){
    if(x >=preOrder.size()) return NULL;
    if(preOrder[x] < ub){
        TreeNode<int> *node = new TreeNode<int>(preOrder[x]);
        x++;
        node->left = func(preOrder,node->data);
        node->right = func(preOrder,ub);
        return node;
    }
    
    return NULL; 
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    x  = 0;
    return func(preOrder,INT_MAX);
}
