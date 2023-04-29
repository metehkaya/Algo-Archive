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
    bool isSameTree(TreeNode* u, TreeNode* v) {
        if(u == NULL && v == NULL)
            return true;
        if(u == NULL || v == NULL)
            return false;
        if(u->val != v->val)
            return false;
        bool left = isSameTree(u->left,v->left);
        bool right = isSameTree(u->right,v->right);
        return left && right;
    }
};