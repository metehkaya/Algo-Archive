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
    bool evaluateTree(TreeNode* node) {
        if(node->val <= 1)
            return (bool) node->val;
        else if(node->val == 2)
            return evaluateTree(node->left) || evaluateTree(node->right);
        else
            return evaluateTree(node->left) && evaluateTree(node->right);
        return false;
    }
};
