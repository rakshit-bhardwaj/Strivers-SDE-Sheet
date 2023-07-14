typedef BinaryTreeNode<int> * t;
void connectNodes(BinaryTreeNode< int > *root) {
    queue<t> q;
    q.push(root);
    t temp;
    while(!q.empty()){
        int size = q.size();
        temp = NULL;
        while(size--){
            auto cur = q.front();
            q.pop();
            if(temp!=NULL) cur->next = temp;
            temp = cur;
            if(cur->right!=NULL) q.push(cur->right);
            if(cur->left!=NULL) q.push(cur->left);
        }
    }
}
