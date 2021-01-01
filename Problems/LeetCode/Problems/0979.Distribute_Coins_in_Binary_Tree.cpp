struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int f(TreeNode* node, int& ans) {
        if(node == NULL)
            return 0;
        node->val += f(node->left,ans);
        node->val += f(node->right,ans);
        ans += abs((node->val) - 1);
        return (node->val) - 1;
    }
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        f(root,ans);
        return ans;
    }
};