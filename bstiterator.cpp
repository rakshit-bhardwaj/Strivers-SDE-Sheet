class BSTiterator
{
    public:
    stack<TreeNode<int>*> s;

    void pushall(TreeNode<int> *root){
        while(root!=NULL){
            s.push(root);
            root = root->left;
        }
    }
    BSTiterator(TreeNode<int> *root)
    {
        pushall(root);
    }

    int next()
    {
        if(s.empty()) return -1;
        auto node = s.top();
        s.pop();
        if(node->right!=NULL) pushall(node->right);
        return node->data;
    }

    bool hasNext()
    {
        return !s.empty();
    }
};
