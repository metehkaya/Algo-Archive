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
    void dfs1(TreeNode* node, set<int>& values) {
        if(node == NULL)
            return;
        values.insert(node->val);
        dfs1(node->left,values);
        dfs1(node->right,values);
    }
    void dfs2(TreeNode* node, set<int>& values, int& target, bool& ans) {
        if(node == NULL)
            return;
        if(values.find(target-node->val) != values.end())
            ans = true;
        dfs2(node->left,values,target,ans);
        dfs2(node->right,values,target,ans);
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        bool ans = false;
        set<int> values;
        dfs1(root1,values);
        dfs2(root2,values,target,ans);
        return ans;
    }
};