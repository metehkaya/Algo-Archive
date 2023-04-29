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
    bool dfs(TreeNode* node) {
        if(node == NULL)
            return false;
        bool ok = (bool) (node->val);
        if(node->left != NULL) {
            if(dfs(node->left))
                ok = true;
            else
                node->left = NULL;
        }
        if(node->right != NULL) {
            if(dfs(node->right))
                ok = true;
            else
                node->right = NULL;
        }
        return ok;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!dfs(root))
            return NULL;
        return root;
    }
};