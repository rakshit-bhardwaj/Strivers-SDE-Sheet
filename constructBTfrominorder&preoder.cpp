TreeNode<int> *build(vector<int> &inorder,int instart,int inend, vector<int> &preorder,int prestart,int preend,unordered_map<int,int> &ino){
    if(prestart > preend || instart > inend) return NULL;
    TreeNode<int> *n = new TreeNode<int>(preorder[prestart]);

    int inind = ino[n->data];
    int numsleft = inind - instart;

    n->left = build(inorder,instart,inind -1,preorder,prestart+1,prestart + numsleft,ino);
    n->right = build(inorder,inind + 1,inend,preorder,prestart + numsleft + 1,preend,ino);
    return n;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	unordered_map<int,int> ino;
    for(int i = 0;i<inorder.size();i++) ino[inorder[i]] = i;

    return build(inorder,0,inorder.size()-1,preorder,0,preorder.size(),ino);
    
}
