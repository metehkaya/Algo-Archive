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
    int heightOfTree(TreeNode* node) {
        if(node->left != NULL and node->left->right == node)
            return 0;
        int mx = 0;
        if(node->left != NULL)
            mx = max(mx,heightOfTree(node->left));
        if(node->right != NULL)
            mx = max(mx,heightOfTree(node->right));
        return ++mx;
    }
};
