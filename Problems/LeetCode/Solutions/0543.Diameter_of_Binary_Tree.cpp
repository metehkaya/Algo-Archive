struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int dfs(TreeNode* node, int& ans) {
        int left = 0 , right = 0;
        if(node->left != NULL)
            left = dfs(node->left, ans) + 1;
        if(node->right != NULL)
            right = dfs(node->right, ans) + 1;
        ans = max(ans, left+right);
        return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ans = 0;
        dfs(root,ans);
        return ans;
    }
};