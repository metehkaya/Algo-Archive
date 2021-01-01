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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        ans.push_back(root->val);
        if(root->left)
            dfsLeft(root->left,ans);
        if(root->left || root->right)
            dfs(root,ans);
        if(root->right)
            dfsRight(root->right,ans);
        return ans;
    }
    void dfs(TreeNode* node , vector<int>& ans) {
        if(node->left == NULL && node->right == NULL) {
            ans.push_back(node->val);
            return;
        }
        else {
            if(node->left)
                dfs(node->left,ans);
            if(node->right)
                dfs(node->right,ans);
        }
    }
    void dfsLeft(TreeNode* node , vector<int>& ans) {
        if(node->left) {
            ans.push_back(node->val);
            dfsLeft(node->left,ans);
        }
        else if(node->right) {
            ans.push_back(node->val);
            dfsLeft(node->right,ans);
        }
    }
    void dfsRight(TreeNode* node , vector<int>& ans) {
        if(node->right) {
            dfsRight(node->right,ans);
            ans.push_back(node->val);
        }
        else if(node->left) {
            dfsRight(node->left,ans);
            ans.push_back(node->val);
        }
    }
};