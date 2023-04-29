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
    bool dfs(TreeNode* node , int t) {
        if(node->left == NULL && node->right == NULL)
            return (t == 0);
        if(node->left != NULL && dfs(node->left,t-node->left->val))
            return true;
        if(node->right != NULL && dfs(node->right,t-node->right->val))
            return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int t) {
        if(root == NULL)
            return false;
        return dfs(root,t-root->val);
    }
};