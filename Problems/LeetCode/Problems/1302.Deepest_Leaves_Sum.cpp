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
    void dfs(TreeNode* node, int lvl, pi& res) {
        if(node == NULL)
            return;
        if(lvl > res.se)
            res = pi( node->val , lvl );
        else if(lvl == res.se)
            res.fi += node->val;
        dfs(node->left, lvl+1, res);
        dfs(node->right, lvl+1, res);
    }
    int deepestLeavesSum(TreeNode* root) {
        pi res = pi(0,0);
        dfs(root,1,res);
        return res.fi;
    }
};