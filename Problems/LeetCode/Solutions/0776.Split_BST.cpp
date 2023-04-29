class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        vector<TreeNode*> ans(2,NULL);
        if(root == NULL)
            return ans;
        if(root->val > target) {
            auto ans_child = splitBST(root->left, target);
            ans[1] = root;
            ans[1]->left = ans_child[1];
            ans[0] = ans_child[0];
        }
        else {
            auto ans_child = splitBST(root->right, target);
            ans[0] = root;
            ans[0]->right = ans_child[0];
            ans[1] = ans_child[1];
        }
        return ans;
    }
};
