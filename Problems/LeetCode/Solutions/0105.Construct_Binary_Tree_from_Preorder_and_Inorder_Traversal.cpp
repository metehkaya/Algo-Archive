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
    vector<int> ar;
    map<int,int> mp;
    TreeNode* solve(int l , int r , int& idx) {
        if(l > r)
            return NULL;
        int m = mp[ar[idx]];
        TreeNode* node = new TreeNode(ar[idx++]);
        node->left = solve(l,m-1,idx);
        node->right = solve(m+1,r,idx);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        ar = preorder;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            mp[inorder[i]] = i;
        int idx = 0;
        return solve(0,n-1,idx);
    }
};