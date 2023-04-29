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
    int dfs(TreeNode* node , map<int,int>& depth) {
        int lvl = 0;
        if(node->left != NULL)
            lvl = max( lvl , dfs(node->left,depth) + 1 );
        if(node->right != NULL)
            lvl = max( lvl , dfs(node->right,depth) + 1 );
        depth[node->val] = lvl;
        return lvl;
    }
    TreeNode* sol(TreeNode* node , map<int,int>& depth) {
        if(node->left == NULL && node->right == NULL)
            return node;
        if(node->left == NULL)
            return sol(node->right,depth);
        if(node->right == NULL)
            return sol(node->left,depth);
        int lVal = depth[node->left->val];
        int rVal = depth[node->right->val];
        if(lVal < rVal)
            return sol(node->right,depth);
        else if(lVal > rVal)
            return sol(node->left,depth);
        return node;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        map<int,int> depth;
        dfs(root,depth);
        return sol(root,depth);
    }
};