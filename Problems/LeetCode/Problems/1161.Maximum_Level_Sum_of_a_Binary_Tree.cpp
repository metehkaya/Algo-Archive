struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode* node, int lvl, vector<int>& sum) {
        if(lvl == sum.size())
            sum.push_back(node->val);
        else
            sum[lvl] += node->val;
        if(node->left != NULL)
            dfs(node->left, lvl+1, sum);
        if(node->right != NULL)
            dfs(node->right, lvl+1, sum);
    }
    int maxLevelSum(TreeNode* root) {
        vector<int> sum;
        dfs(root, 0, sum);
        int best = 0;
        for( int i = 1 ; i < sum.size() ; i++ )
            if(sum[i] > sum[best])
                best = i;
        return best+1;
    }
};