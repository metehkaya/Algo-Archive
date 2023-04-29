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
    void dfs(TreeNode* node , int lvl , int& ans) {
        if(node->left == NULL && node->right == NULL) {
            ans = min(ans,lvl);
            return;
        }
        if(node->left)
            dfs(node->left,lvl+1,ans);
        if(node->right)
            dfs(node->right,lvl+1,ans);
    }
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ans = INT_MAX;
        dfs(root,1,ans);
        return ans;
    }
};