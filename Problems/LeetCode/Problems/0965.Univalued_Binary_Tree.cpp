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
    bool isUnivalTree(TreeNode* node , int val = -1) {
        if(node == NULL)
            return true;
        if(val != -1 && node->val != val)
            return false;
        if(val == -1)
            val = node->val;
        return isUnivalTree(node->left,val) and isUnivalTree(node->right,val);
    }
};