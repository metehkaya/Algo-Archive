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
    int ans = INT_MAX;
    pi dfs(TreeNode* node) {
        pi p = pi(node->val,node->val);
        if(node->left) {
            pi c = dfs(node->left);
            ans = min(ans,node->val-c.se);
            p.fi = c.fi;
        }
        if(node->right) {
            pi c = dfs(node->right);
            ans = min(ans,c.fi-node->val);
            p.se = c.se;
        }
        return p;
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};