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
    void dfs(TreeNode* node , int& mn , int& mx , int& ans) {
        if(node == NULL)
            return;
        mn = mx = node->val;
        if(node->left) {
            int mnc,mxc;
            dfs(node->left,mnc,mxc,ans);
            mn = min(mn,mnc);
            mx = max(mx,mxc);
        }
        if(node->right) {
            int mnc,mxc;
            dfs(node->right,mnc,mxc,ans);
            mn = min(mn,mnc);
            mx = max(mx,mxc);
        }
        if(mn == mx)
            ans++;
    }
    int countUnivalSubtrees(TreeNode* root) {
        int ans = 0 , mn , mx;
        dfs(root,mn,mx,ans);
        return ans;
    }
};