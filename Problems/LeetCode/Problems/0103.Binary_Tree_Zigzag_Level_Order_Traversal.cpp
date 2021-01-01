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
        if(ans.size() == lvl)
            ans.resize(lvl+1);
        ans[lvl].push_back(node->val);
        dfs(node->left,lvl+1,ans);
        dfs(node->right,lvl+1,ans);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root,0,ans);
        int lvl = ans.size();
        for( int i = 1 ; i < lvl ; i += 2 )
            reverse(ans[i].begin(),ans[i].end());
        return ans;
    }
};