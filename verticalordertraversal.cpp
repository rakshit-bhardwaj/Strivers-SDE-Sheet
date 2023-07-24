
vector<int> verticalOrderTraversal(TreeNode<int> *root) {
    vector<int> ans;
    if (root == NULL) return ans;

    map<int, vector<int>> m;
    queue<pair<TreeNode<int>*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto nodePair = q.front();
        q.pop();
        TreeNode<int>* node = nodePair.first;
        int lr = nodePair.second;

        m[lr].push_back(node->data);

        if (node->left != NULL) {
            q.push({node->left, lr - 1});
        }

        if (node->right != NULL) {
            q.push({node->right, lr + 1});
        }
    }

    for (const auto& x : m) {
        ans.insert(ans.end(), x.second.begin(), x.second.end());
    }

    return ans;
}
