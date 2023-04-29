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
    int dfs(TreeNode* node, int& k) {
        if(node == NULL)
            return INT_MIN;
        int val;
        val = dfs(node->left, k);
        if(val != INT_MIN)
            return val;
        if(--k == 0)
            return node->val;
        val = dfs(node->right, k);
        return val;
    }
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root,k);
    }
};