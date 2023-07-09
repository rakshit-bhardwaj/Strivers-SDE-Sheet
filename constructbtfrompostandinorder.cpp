#include<bits/stdc++.h>
TreeNode<int>* solve(vector<int>& post,int postStart,int postEnd, int inStart ,int inEnd,map<int,int>&inMap){
       if(postStart > postEnd || inStart > inEnd) return NULL;

       TreeNode<int>* root = new TreeNode<int>(post[postEnd]);
       int inRoot=inMap[root->data];
       int numsLeft=inRoot - inStart;

       root->left=solve(post,postStart,postStart+numsLeft-1,inStart,inRoot-1,inMap);
       root->right=solve(post,postStart+numsLeft ,postEnd-1,inRoot+1,inEnd,inMap);

       return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
      if(inOrder.size() != postOrder.size())return NULL;
          map<int,int>inMap;
	     int n=postOrder.size();
          for(int i=0;i<n;++i){
               inMap[inOrder[i]]=i;
          }

     return solve(postOrder,0,n-1,0,n-1,inMap);
}
