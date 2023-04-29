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
    vector<vector<string>> ans;
    int dfs(TreeNode* node) {
        if(node == NULL)
            return 0;
        return max(dfs(node->left),dfs(node->right))+1;
    }
    void solve(TreeNode* node , int l , int r , int lvl) {
        if(node == NULL)
            return;
        int m = (l+r) >> 1;
        ans[lvl][m] = to_string(node->val);
        if(l == r)
            return;
        solve(node->left,l,m-1,lvl+1);
        solve(node->right,m+1,r,lvl+1);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int depth = dfs(root);
        int d = (1 << depth);
        ans.resize(depth);
        for( int i = 0 ; i < depth ; i++ )
            ans[i].resize(d-1,"");
        solve(root,0,d-2,0);
        return ans;
    }
};