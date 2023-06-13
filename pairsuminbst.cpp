void findinorder(BinaryTreeNode<int> *node,vector<int> &inorder){
    if(node==NULL) return;
    findinorder(node->left,inorder);
    inorder.push_back(node->data);
    findinorder(node->right,inorder);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int> inorder;
    findinorder(root,inorder);
    for(int i =0;i<inorder.size()-1;i++){
        int x = k - inorder[i];
        int s = i+1,e = inorder.size()-1;
        while(s<=e){
            int m = (s+e) >> 1;
            if(inorder[m]== x) return true;
            if(inorder[m] > x) e = m-1;
            else s = m+1;
        }
    }
    return false;
}
