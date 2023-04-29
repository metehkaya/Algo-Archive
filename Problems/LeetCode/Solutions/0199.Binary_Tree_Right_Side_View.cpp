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
    vector<int> ans;
    void dfs(TreeNode* node , int lvl) {
        if(node == NULL)
            return;
        if(lvl == ans.size())
            ans.push_back(node->val);
        dfs(node->right,lvl+1);
        dfs(node->left,lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};