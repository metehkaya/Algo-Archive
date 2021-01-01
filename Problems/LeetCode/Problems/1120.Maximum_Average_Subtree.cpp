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
    pi dfs(TreeNode* node , double& ans) {
        if(node == NULL)
            return pi(0,0);
        pi p = pi(node->val,1);
        pi l = dfs(node->left,ans);
        p.first += l.first , p.second += l.second;
        pi r = dfs(node->right,ans);
        p.first += r.first , p.second += r.second;
        double val = (double) p.first / p.second;
        ans = max(ans,val);
        return p;
    }
    double maximumAverageSubtree(TreeNode* root) {
        double ans = 0.0;
        dfs(root,ans);
        return ans;
    }
};