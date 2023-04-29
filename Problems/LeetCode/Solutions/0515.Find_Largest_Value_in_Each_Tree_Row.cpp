struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode* node, vector<int>& ans, int lvl) {
        if(lvl >= ans.size())
            ans.push_back(node->val);
        else
            ans[lvl] = max( ans[lvl] , node->val );
        if(node->left != NULL)
            dfs(node->left, ans, lvl+1);
        if(node->right != NULL)
            dfs(node->right, ans, lvl+1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        dfs(root,ans,0);
        return ans;
    }
};