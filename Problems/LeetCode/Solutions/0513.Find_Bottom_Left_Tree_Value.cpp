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
    int ans,depth;
    void dfs(TreeNode* node , int d) {
        if(node == NULL)
            return;
        if(d > depth) {
            depth = d;
            ans = node->val;
        }
        dfs(node->left,d+1);
        dfs(node->right,d+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root,1);
        return ans;
    }
};