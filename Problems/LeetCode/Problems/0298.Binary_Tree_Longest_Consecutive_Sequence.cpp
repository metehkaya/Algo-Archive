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
    int ans = 0;
    int dfs(TreeNode* node) {
        int res = 1;
        if(node->left) {
            int val = dfs(node->left);
            if(node->val == node->left->val - 1)
                res = max(res,val+1);
        }
        if(node->right) {
            int val = dfs(node->right);
            if(node->val == node->right->val - 1)
                res = max(res,val+1);
        }
        ans = max(ans,res);
        return res;
    }
    int longestConsecutive(TreeNode* root) {
        if(root == NULL)
            return ans;
        dfs(root);
        return ans;
    }
};