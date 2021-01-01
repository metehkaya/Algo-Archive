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
    int dfs(TreeNode* node , int limit , int sum) {
        if(node->left == NULL && node->right == NULL)
            return sum;
        int mx = INT_MIN;
        if(node->left != NULL) {
            int val = dfs(node->left,limit,sum+node->left->val);
            mx = max(mx,val);
            if(val < limit) {
                delete node->left;
                node->left = NULL;
            }
        }
        if(node->right != NULL) {
            int val = dfs(node->right,limit,sum+node->right->val);
            mx = max(mx,val);
            if(val < limit) {
                delete node->right;
                node->right = NULL;
            }
        }
        return mx;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int mx = dfs(root,limit,root->val);
        if(mx < limit)
            root = NULL;
        return root;
    }
};