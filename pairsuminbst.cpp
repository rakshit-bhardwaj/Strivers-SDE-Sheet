#include <bits/stdc++.h> 
class BSTIterator {
    stack<BinaryTreeNode<int> *> myStack;
    bool reverse = true; 
public:
    BSTIterator(BinaryTreeNode<int> *root, bool isReverse) {
        reverse = isReverse; 
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        BinaryTreeNode<int> *tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->data;
    }

private:
    void pushAll(BinaryTreeNode<int> *node) {
        for(;node != NULL; ) {
             myStack.push(node);
             if(reverse == true) {
                 node = node->right; 
             } else {
                 node = node->left; 
             }
        }
    }
};

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    BSTIterator l(root,false),r(root,true);
    int i = l.next();
    int j = r.next();

    while(i<j){
        if(i+j==k) return true;
        if(i+j < k) i = l.next();
        else j = r.next(); 
    }
    return false;
}
