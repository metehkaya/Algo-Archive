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
    pi dfs(TreeNode* node, int& ans) {
        pi res = pi(0,0);
        if(node->left != NULL) {
            pi temp = dfs(node->left, ans);
            res.fi = temp.se + 1;
        }
        if(node->right != NULL) {
            pi temp = dfs(node->right, ans);
            res.se = temp.fi + 1;
        }
        ans = max(ans, max(res.fi, res.se));
        return res;
    }
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};