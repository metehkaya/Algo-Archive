#define fi first
#define se second
typedef pair<int,int> pi;

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
    pi dfs(TreeNode* node) {
        if(node == NULL)
            return pi(0,0);
        pi res;
        pi l = dfs(node->left);
        pi r = dfs(node->right);
        res.fi = l.se + r.se;
        res.se = max(res.fi,l.fi+r.fi+node->val);
        return res;
    }
    int rob(TreeNode* root) {
        return dfs(root).se;
    }
};