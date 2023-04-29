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
    const int K = 10;
    int dfs( TreeNode* node , vector<bool>& isEven ) {
        if(node == NULL)
            return 0;
        int res = 0;
        isEven[node->val] = !isEven[node->val];
        if( node->left == NULL && node->right == NULL ) {
            int cntOdd = 0;
            for( int i = 0 ; i < K ; i++ )
                cntOdd += !isEven[i];
            if(cntOdd <= 1)
                res++;
        }
        else {
            res += dfs( node->left , isEven );
            res += dfs( node->right , isEven );
        }
        isEven[node->val] = !isEven[node->val];
        return res;
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<bool> isEven(K,true);
        return dfs(root,isEven);
    }
};