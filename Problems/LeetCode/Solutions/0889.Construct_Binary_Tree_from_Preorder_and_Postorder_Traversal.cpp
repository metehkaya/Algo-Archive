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
    int n;
    int inv[31];
    vector<int> preorder, postorder;
    TreeNode* f(int pre_l , int pre_r , int post_l , int post_r) {
        TreeNode* node = new TreeNode(preorder[pre_l]);
        int sz = pre_r - pre_l + 1;
        if(sz == 1)
            return node;
        int idx_l = inv[preorder[pre_l+1]];
        int sz_l = idx_l - post_l + 1;
        int sz_r = sz - sz_l - 1;
        node->left = f(pre_l+1,pre_l+sz_l,post_l,idx_l);
        if(sz_r)
            node->right = f(pre_l+sz_l+1,pre_r,idx_l+1,post_r-1);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        n = preorder.size();
        this->preorder = preorder;
        this->postorder = postorder;
        for( int i = 0 ; i < n ; i++ )
            inv[postorder[i]] = i;
        return f(0,n-1,0,n-1);
    }
};