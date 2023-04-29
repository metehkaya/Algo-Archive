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
    void dfs(TreeNode* node , bool add) {
        if(add)
            ans.push_back(node->val);
        if(node->left)
            dfs(node->left,node->right==NULL);
        if(node->right)
            dfs(node->right,node->left==NULL);
    }
    vector<int> getLonelyNodes(TreeNode* root) {
        dfs(root,false);
        return ans;
    }
};