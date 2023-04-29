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
    int dfs(TreeNode* node, int& ans) {
        if(node == NULL)
            return 0;
        int leftChain = max( dfs(node->left, ans) , 0 );
        int rightChain = max( dfs(node->right, ans) , 0 );
        int chain = max( leftChain , rightChain ) + node->val;
        ans = max( ans , leftChain + rightChain + node->val );
        return chain;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
};