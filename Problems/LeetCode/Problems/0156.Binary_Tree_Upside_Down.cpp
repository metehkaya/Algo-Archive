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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        if(root->left) {
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            TreeNode* res = upsideDownBinaryTree(l);
            upsideDownBinaryTree(r);
            root->left = root->right = NULL;
            l->left = r;
            l->right = root;
            return res;
        }
        return root;
    }
};