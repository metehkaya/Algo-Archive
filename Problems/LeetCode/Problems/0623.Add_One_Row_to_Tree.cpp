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
    void solve(TreeNode* node , int lvl , int d , int v) {
        if(node == NULL)
            return;
        if(lvl == d-1) {
            TreeNode* nl = node->left;
            TreeNode* nr = node->right;
            node->left = new TreeNode(v);
            node->left->left = nl;
            node->right = new TreeNode(v);
            node->right->right = nr;
            return;
        }
        solve(node->left,lvl+1,d,v);
        solve(node->right,lvl+1,d,v);
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        solve(root,1,d,v);
        return root;
    }
};