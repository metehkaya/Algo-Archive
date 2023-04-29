class Solution {
public:
    int ans;
    vector<int> f(TreeNode* node) {
        vector<int> res({1,1});
        if(node->left) {
            vector<int> v = f(node->left);
            if(node->left->val == node->val-1)
                res[0] = max(res[0],v[0]+1);
            if(node->left->val == node->val+1)
                res[1] = max(res[1],v[1]+1);
        }
        if(node->right) {
            vector<int> v = f(node->right);
            if(node->right->val == node->val-1)
                res[0] = max(res[0],v[0]+1);
            if(node->right->val == node->val+1)
                res[1] = max(res[1],v[1]+1);
        }
        ans = max(ans,res[0]+res[1]-1);
        return res;
    }
    int longestConsecutive(TreeNode* root) {
        f(root);
        return ans;
    }
};
