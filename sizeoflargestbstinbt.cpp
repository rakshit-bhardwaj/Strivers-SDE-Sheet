vector<int> solve(TreeNode<int> *node){
    vector<int> v = {0,INT_MIN,INT_MAX,1};
    if(node==NULL) return v;
    vector<int> a = solve(node->left);
    vector<int> b = solve(node->right);

    if(a[3] == 1 && b[3] ==1 && node->data > a[1] && node->data < b[2]){
        v[0] = 1 + a[0] + b[0];
        v[1] = max(node->data,b[1]);
        v[2] = min(node->data,a[2]);
        v[3] = 1;
    } else {
      v[0] = max(a[0], b[0]);
      v[3] = 0;
    }

    return v;
}
int largestBST(TreeNode<int>* root) 
{
    vector<int> v = solve(root);
    return v[0];
}
