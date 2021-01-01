typedef long long LL;

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
    const int MOD = (int) 1e9 + 7;
    int dfs(TreeNode* node , vector<int>& sums) {
        if(node == NULL)
            return 0;
        int sum = node->val;
        sum += dfs(node->left , sums);
        sum += dfs(node->right , sums);
        sums.push_back(sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        vector<int> sums;
        dfs(root,sums);
        int n = sums.size();
        int total = sums[n-1];
        LL ans = 0;
        for( int i = 0 ; i < n-1 ; i++ )
            ans = max( ans , (LL) sums[i] * (total - sums[i]) );
        return ans % MOD;
    }
};