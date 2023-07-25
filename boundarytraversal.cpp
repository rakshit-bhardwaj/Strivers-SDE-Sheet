#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isleaf(TreeNode<int>*root){
    return (root->left == NULL) & (root->right==NULL);
}
void lb(TreeNode<int>* root,vector<int> &res){
    TreeNode<int>* cur = root->left;
    while(cur){
        if(!isleaf(cur)) res.push_back(cur->data);
        if(cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void rb(TreeNode<int>* root,vector<int> &res){
    TreeNode<int>* cur = root->right;
    vector<int> t;
    while(cur){
        if(!isleaf(cur)) t.push_back(cur->data);
        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }
    for(int i = t.size()-1;i>=0;i--){
        res.push_back(t[i]);
    }
}

void addleafs(TreeNode<int>*root,vector<int> &res){
    if(isleaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) addleafs(root->left,res);
    if(root->right) addleafs(root->right,res);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    if(!isleaf(root)) res.push_back(root->data);
    lb(root,res);
    addleafs(root,res);
    rb(root,res);
    return res;
}
