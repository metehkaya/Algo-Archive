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
    void dfs(TreeNode* node, vector<int>& v) {
        if(node == NULL)
            return;
        dfs(node->left, v);
        v.push_back(node->val);
        dfs(node->right, v);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> v;
        dfs(root,v);
        int n = queries.size();
        vector<vector<int>> ans(n,vector<int>(2,-1));
        for( int i = 0 ; i < n ; i++ ) {
            int q = queries[i];
            auto it = upper_bound(v.begin(), v.end(), q);
            if(it != v.begin()) {
                it--;
                ans[i][0] = (*it);
            }
            it = lower_bound(v.begin(), v.end(), q);
            if(it != v.end())
                ans[i][1] = (*it);
        }
        return ans;
    }
};
