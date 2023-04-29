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
    void dfs(TreeNode* node , int lvl , vector<vector<int>>& ans) {
        if(node == NULL)
            return;
        if(lvl > ans.size())
            ans.resize(lvl);
        ans[lvl-1].push_back(node->val);
        dfs(node->left,lvl+1,ans);
        dfs(node->right,lvl+1,ans);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root,1,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};