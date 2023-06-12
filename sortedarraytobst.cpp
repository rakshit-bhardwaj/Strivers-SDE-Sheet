TreeNode<int>* build(vector<int> &arr,int l,int r){
    if(l>r) return NULL;
    int mid = (r+l)/2;
    TreeNode<int> * n = new TreeNode<int>(arr[mid]);
    n->left = build(arr,l,mid-1);
    n->right = build(arr,mid+1,r);
    return n;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return build(arr,0,n-1);
}
