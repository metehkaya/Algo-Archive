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
    int dfs(TreeNode* node , vector<int>& sum) {
        int total = node->val;
        if(node->left)
            total += dfs(node->left,sum);
        if(node->right)
            total += dfs(node->right,sum);
        sum.push_back(total);
        return total;
    }
    bool checkEqualTree(TreeNode* root) {
        vector<int> sum;
        dfs(root,sum);
        int n = sum.size();
        for( int i = 0 ; i < n-1 ; i++ )
            if(2*sum[i] == sum[n-1])
                return true;
        return false;
    }
};