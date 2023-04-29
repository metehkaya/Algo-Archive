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
    unordered_map<TreeNode*,int> mp;
    int dfs(TreeNode* node) {
        int h = 0;
        if(node->left)
            h = max(h,dfs(node->left)+1);
        if(node->right)
            h = max(h,dfs(node->right)+1);
        mp[node] = h;
        return h;
    }
    TreeNode* solve(TreeNode* node) {
        if(!node->left && !node->right)
            return node;
        if(!node->left)
            return solve(node->right);
        if(!node->right)
            return solve(node->left);
        int l = mp[node->left];
        int r = mp[node->right];
        if(l > r)
            return solve(node->left);
        else if(l < r)
            return solve(node->right);
        else
            return node;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root);
        return solve(root);
    }
};