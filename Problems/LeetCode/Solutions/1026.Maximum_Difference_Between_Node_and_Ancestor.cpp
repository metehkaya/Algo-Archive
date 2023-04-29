struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int dfs(TreeNode* node, int mn, int mx) {
        mn = min(mn, node->val);
        mx = max(mx, node->val);
        int ans = mx-mn;
        if(node->left != NULL)
            ans = max(ans, dfs(node->left, mn, mx));
        if(node->right != NULL)
            ans = max(ans, dfs(node->right, mn, mx));
        return ans;
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL)
            return 0;
        return dfs(root, root->val, root->val);
    }
};