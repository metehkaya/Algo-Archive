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
    TreeNode* searchBST(TreeNode* node, int val) {
        TreeNode* res;
        if(node == NULL)
            res = NULL;
        else if(val == node->val)
            res = node;
        else if(val < node->val)
            res = searchBST(node->left,val);
        else
            res = searchBST(node->right,val);
        return res;
    }
};