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
    int sumNumbers(TreeNode* root, int val = 0) {
        if(root == NULL)
            return 0;
        val = 10*val + root->val;
        if(root->left == NULL && root->right == NULL)
            return val;
        return sumNumbers(root->left,val) + sumNumbers(root->right,val);
    }
};