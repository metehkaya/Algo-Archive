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
    int dfs(TreeNode* node , bool isLeft) {
        if(node == NULL)
            return 0;
        if(!node->left && !node->right)
            return isLeft ? node->val : 0;
        return dfs(node->left,true) + dfs(node->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root,false);
    }
};