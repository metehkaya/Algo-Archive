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
    vector<vector<int>> ans;
    int dfs(TreeNode* node) {
        int h = 0;
        if(node->left)
            h = max(h,dfs(node->left)+1);
        if(node->right)
            h = max(h,dfs(node->right)+1);
        if(h == ans.size()) {
            vector<int> v(1,node->val);
            ans.push_back(v);
        }
        else
            ans[h].push_back(node->val);
        return h;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(root)
            dfs(root);
        return ans;
    }
};