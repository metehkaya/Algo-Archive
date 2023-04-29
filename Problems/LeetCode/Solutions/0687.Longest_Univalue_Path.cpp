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
    int ans;
    int dfs(TreeNode* node) {
        int val = node->val;
        int left = 0 , right = 0;
        if(node->left != NULL) {
            int cnt = dfs(node->left);
            if(val == node->left->val)
                left = cnt;
        }
        if(node->right != NULL) {
            int cnt = dfs(node->right);
            if(val == node->right->val)
                right = cnt;
        }
        ans = max(ans,left+right);
        return max(left,right)+1;
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root != NULL)
            dfs(root);
        return ans;
    }
};