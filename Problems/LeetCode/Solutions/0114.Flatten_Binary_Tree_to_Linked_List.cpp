struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> nodes;
    void dfs(TreeNode* node) {
        if(node == NULL)
            return;
        nodes.push_back(node);
        dfs(node->left);
        dfs(node->right);
    }
    void flatten(TreeNode* root) {
        dfs(root);
        int n = nodes.size();
        for( int i = 0 ; i < n ; i++ ) {
            nodes[i]->left = NULL;
            nodes[i]->right = (i == n-1) ? NULL : nodes[i+1];
        }
    }
};