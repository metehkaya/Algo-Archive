typedef long long LL;

class Solution {
public:
    LL dfs(TreeNode* node , int& ans) {
        if(node == NULL)
            return 0;
        LL sum = dfs(node->left,ans) + dfs(node->right,ans);
        if(node->val == sum)
            ans++;
        sum += node->val;
        return sum;
    }
    int equalToDescendants(TreeNode* root) {
        int ans = 0;
        dfs(root,ans);
        return ans;
    }
};
