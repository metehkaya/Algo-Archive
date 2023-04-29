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
    void dfs( TreeNode* node , vector<int>& v ) {
        if(node == NULL)
            return;
        dfs(node->left,v);
        v.push_back(node->val);
        dfs(node->right,v);
    }
    TreeNode* solve( int l , int r , vector<int>& v ) {
        if(l > r)
            return NULL;
        int mid = (l+r) >> 1;
        TreeNode* node = new TreeNode(v[mid]);
        node->left = solve(l,mid-1,v);
        node->right = solve(mid+1,r,v);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        dfs(root,v);
        int n = v.size();
        return solve(0,n-1,v);
    }
};