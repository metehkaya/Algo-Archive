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
    int sumRootToLeaf(TreeNode* node , int val = 0) {
        if(node == NULL)
            return 0;
        val = 2*val + node->val;
        if(node->left == NULL && node->right == NULL)
            return val;
        int ans = 0;
        ans += sumRootToLeaf(node->left,val);
        ans += sumRootToLeaf(node->right,val);
        return ans;
    }
};