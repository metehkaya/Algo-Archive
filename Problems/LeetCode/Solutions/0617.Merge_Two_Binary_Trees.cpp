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
    TreeNode* mergeTrees(TreeNode* u, TreeNode* v) {
        if(u == NULL && v == NULL)
            return NULL;
        if(v == NULL)
            return u;
        else if(u == NULL)
            return v;
        TreeNode* node = new TreeNode(u->val+v->val);
        node->left = mergeTrees(u->left,v->left);
        node->right = mergeTrees(u->right,v->right);
        return node;
    }
};