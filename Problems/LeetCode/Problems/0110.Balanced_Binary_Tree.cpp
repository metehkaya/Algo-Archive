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
    int dfs(TreeNode* node) {
        if(node == NULL)
            return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);
        if(l == -1 || r == -1 || abs(l-r) > 1)
            return -1;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};