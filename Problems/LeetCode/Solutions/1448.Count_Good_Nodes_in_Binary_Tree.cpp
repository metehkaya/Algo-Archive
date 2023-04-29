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
    int dfs(TreeNode* node, int mx) {
        if(node == NULL)
            return 0;
        int res = 0;
        mx = max( mx , node->val );
        if( node->val >= mx )
            res++;
        res += dfs(node->left, mx);
        res += dfs(node->right, mx);
        return res;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};