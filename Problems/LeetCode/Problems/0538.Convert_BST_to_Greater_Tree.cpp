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
    void dfs(TreeNode* node , TreeNode* ans , int& sum) {
        if(node->right) {
            ans->right = new TreeNode();
            dfs(node->right,ans->right,sum);
        }
        sum += node->val;
        ans->val = sum;
        if(node->left) {
            ans->left = new TreeNode();
            dfs(node->left,ans->left,sum);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL)
            return NULL;
        TreeNode* ans = new TreeNode();
        int sum = 0;
        dfs(root,ans,sum);
        return ans;
    }
};