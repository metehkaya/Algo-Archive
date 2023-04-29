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
    vector<string> ans;
    void dfs(TreeNode* node , string s) {
        if(node->left == NULL && node->right == NULL) {
            ans.push_back(s);
            return;
        }
        if(node->left != NULL)
            dfs(node->left,s+"->"+to_string(node->left->val));
        if(node->right != NULL)
            dfs(node->right,s+"->"+to_string(node->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,to_string(root->val));
        return ans;
    }
};