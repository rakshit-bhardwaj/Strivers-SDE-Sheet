#include <bits/stdc++.h> 
using namespace std;

/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int> *prev = NULL;

void func(TreeNode<int>* root){
    if(root== NULL) return;

    func(root->right);
    func(root->left);

    root->right = prev;
    root->left = NULL;
    prev = root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    func(root);
    return root;
}
