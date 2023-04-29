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
    bool found;
    int ans,minval;
    void dfs(TreeNode* node) {
        if(node == NULL)
            return;
        int val = node->val;
        if(val > minval) {
            found = true;
            ans = min(ans,val);
        }
        dfs(node->left);
        dfs(node->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        ans = INT_MAX;
        found = false;
        minval = root->val;
        dfs(root);
        return found ? ans : -1;
    }
};