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
    vector<int> ar;
    TreeNode* f(int l , int r) {
        if(l > r)
            return NULL;
        else if(l == r)
            return new TreeNode(ar[l]);
        int best = l;
        for( int i = l+1 ; i <= r ; i++ )
            if(ar[i] > ar[best])
                best = i;
        TreeNode* res = new TreeNode(ar[best]);
        res->left = f(l,best-1);
        res->right = f(best+1,r);
        return res;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& ar) {
        this->ar = ar;
        n = ar.size();
        return f(0,n-1);
    }
};