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
    bool dfs(TreeNode* node, vector<int>& ar, int lvl, int n) {
        if(lvl == n)
            return node->left == NULL and node->right == NULL;
        if(node->left != NULL && node->left->val == ar[lvl])
            if( dfs(node->left, ar, lvl+1, n) )
                return true;
        if(node->right != NULL && node->right->val == ar[lvl])
            if( dfs(node->right, ar, lvl+1, n) )
                return true;
        return false;
    }
    bool isValidSequence(TreeNode* root, vector<int>& ar) {
        if(root == NULL or root->val != ar[0])
            return false;
        int n = ar.size();
        return dfs(root, ar, 1, n);
    }
};