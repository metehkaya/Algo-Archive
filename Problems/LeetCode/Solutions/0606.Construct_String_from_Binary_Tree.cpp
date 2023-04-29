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
    string ans;
    void dfs(TreeNode* node) {
        ans += to_string(node->val);
        if(node->left) {
            ans.push_back('(');
            dfs(node->left);
            ans.push_back(')');
        }
        if(node->right) {
            if(node->left == NULL)
                ans += "()";
            ans.push_back('(');
            dfs(node->right);
            ans.push_back(')');
        }
    }
    string tree2str(TreeNode* root) {
        dfs(root);
        return ans;
    }
};