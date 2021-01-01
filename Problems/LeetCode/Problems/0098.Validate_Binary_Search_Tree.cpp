struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValid(TreeNode* root, long long low, long long high) {
        if(root == NULL)
            return true;
        if(low > high)
            return false;
        if(root->val > high || root->val < low)
            return false;
        return isValid(root->left, low, root->val - 1LL) && isValid(root->right, root->val + 1LL, high);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};