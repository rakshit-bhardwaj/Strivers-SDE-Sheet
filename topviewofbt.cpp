#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
     vector<int> ans;
    map<int,pair<int,int>> m;
    queue<pair<TreeNode<int>*,pair<int,int>>> q; 
    if(root==NULL) return ans;
    q.push({root,{0,0}});
    while(!q.empty()){
        int size = q.size();
        while(size--){
            auto cur = q.front();
            int curdep = cur.second.second;
            int curlr = cur.second.first;
            q.pop();
            if (m.find(curlr) == m.end() || m[curlr].second > curdep) {
              m[curlr] = {cur.first->val, curdep};
            }
            if(cur.first->left!=NULL) q.push({cur.first->left, {curlr-1,curdep+1}});
            if(cur.first->right!=NULL) q.push({cur.first->right, {curlr+1,curdep+1}});
        }
    }

    vector<pair<int,int>> med;
    for(auto x : m) med.push_back({x.first,x.second.first});
    sort(med.begin(),med.end());
    for(auto x : med) ans.push_back(x.second);
    return ans;
}
