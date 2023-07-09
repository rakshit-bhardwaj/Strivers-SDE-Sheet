vector<int> bottomView(BinaryTreeNode<int> * root){

    vector<int> ans;
    map<int,pair<int,int>> m;
    queue<pair<BinaryTreeNode<int>*,pair<int,int>>> q; 
    q.push({root,{0,0}});
    while(!q.empty()){
        int size = q.size();
        while(size--){
            auto cur = q.front();
            int curdep = cur.second.second;
            int curlr = cur.second.first;
            q.pop();
            if (m.find(curlr) == m.end() || m[curlr].second <= curdep) {
              m[curlr] = {cur.first->data, curdep};
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
