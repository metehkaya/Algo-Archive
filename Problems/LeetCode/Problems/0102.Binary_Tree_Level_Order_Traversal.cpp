struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode* root, int lvl, vector<vector<int>>& ans) {
        if(root == NULL)
            return;
        if(lvl > (int) ans.size() )
            ans.resize(lvl);
        ans[lvl-1].push_back(root->val);
        dfs(root->left, lvl+1, ans);
        dfs(root->right, lvl+1, ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 1, ans);
        return ans;
    }
};