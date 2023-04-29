class Solution {
public:
    unordered_map<TreeNode*,int> dp[2];
    int f(TreeNode* node , int k) {
        auto it = dp[k].find(node);
        if(it != dp[k].end())
            return it->second;
        int res;
        if(node->val <= 1)
            res = (k != node->val);
        else if(node->val == 5) {
            TreeNode* child = (node->left == NULL) ? node->right : node->left;
            res = f(child,!k);
        }
        else if(node->val == 2) {
            res = INT_MAX;
            for( int i = 0 ; i < 2 ; i++ )
                for( int j = 0 ; j < 2 ; j++ )
                    if((i | j) == k)
                        res = min(res,f(node->left,i)+f(node->right,j));
        }
        else if(node->val == 3) {
            res = INT_MAX;
            for( int i = 0 ; i < 2 ; i++ )
                for( int j = 0 ; j < 2 ; j++ )
                    if((i & j) == k)
                        res = min(res,f(node->left,i)+f(node->right,j));
        }
        else if(node->val == 4) {
            res = INT_MAX;
            for( int i = 0 ; i < 2 ; i++ )
                for( int j = 0 ; j < 2 ; j++ )
                    if((i ^ j) == k)
                        res = min(res,f(node->left,i)+f(node->right,j));
        }
        return dp[k][node] = res;
    }
    int minimumFlips(TreeNode* root, bool result) {
        return f(root,result);
    }
};
