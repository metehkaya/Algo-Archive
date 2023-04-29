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
    static const int maxn = 100003;
    int height[maxn];
    int ans[maxn];
    int dfs(TreeNode* node) {
        int h = 0;
        if(node->left)
            h = max(h,dfs(node->left)+1);
        if(node->right)
            h = max(h,dfs(node->right)+1);
        return height[node->val] = h;
    }
    void solve(TreeNode* node , int d , int other) {
        ans[node->val] = other;
        other = max(other,d);
        if(node->left) {
            int other_l = other;
            if(node->right)
                other_l = max(other_l,d+height[node->right->val]+1);
            solve(node->left,d+1,other_l);
        }
        if(node->right) {
            int other_r = other;
            if(node->left)
                other_r = max(other_r,d+height[node->left->val]+1);
            solve(node->right,d+1,other_r);
        }
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root);
        solve(root,0,-1);
        vector<int> res;
        for(int q : queries)
            res.push_back(ans[q]);
        return res;
    }
};
