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
    vector<TreeNode*> dp[21];
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N % 2 == 0)
            return dp[N];
        dp[1].push_back(new TreeNode(0));
        for( int n = 3 ; n <= N ; n += 2 )
            for( int i = 1 ; i < n ; i += 2 ) {
                int j = n-1-i;
                int szi = dp[i].size();
                int szj = dp[j].size();
                for( int ki = 0 ; ki < szi ; ki++ )
                    for( int kj = 0 ; kj < szj ; kj++ ) {
                        TreeNode* node = new TreeNode(0);
                        node->left = dp[i][ki];
                        node->right = dp[j][kj];
                        dp[n].push_back(node);
                    }
            }
        return dp[N];
    }
};