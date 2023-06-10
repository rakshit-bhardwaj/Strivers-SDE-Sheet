//using temp vector and queue
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root==NULL) return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    int lr = 1;
    while(!q.empty()){
        int size = q.size();
        vector<int> t(size);
        for(int i =0;i<size;i++){
            auto cur = q.front();
            q.pop();
            int index = lr ? i : size - i - 1;
            t[index] = cur->data;
            if(cur->left!=NULL) q.push(cur->left);
            if(cur->right!=NULL) q.push(cur->right);
        }
        lr = !lr;
        ans.insert(ans.end(),t.begin(),t.end());
    }
    return ans;
}
//using dequeue
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root==NULL) return ans;
    deque<BinaryTreeNode<int>*> q;
    q.push_front(root);
    int lr = 1;
    while(!q.empty()){
        int size = q.size();
        for(int i =0;i<size;i++){
            BinaryTreeNode<int> *cur;
          if (lr) {
            cur = q.front();
            q.pop_front();
          } else {
              cur = q.back();
              q.pop_back();
          }
          ans.push_back(cur->data);
          if(lr){
              if(cur->left!=NULL) q.push_back(cur->left);
                if(cur->right!=NULL) q.push_back(cur->right);
          } else {
              if(cur->right!=NULL) q.push_front(cur->right);
              if(cur->left!=NULL) q.push_front(cur->left);
          } 
        }
        lr = !lr;
    }
    return ans;
}
