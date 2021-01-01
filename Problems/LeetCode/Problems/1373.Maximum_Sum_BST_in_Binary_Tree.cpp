#define fi first
#define se second
typedef pair<int,int> pi;
typedef pair<pi,int> ppi;

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
    const ppi INVALID = ppi( pi(INT_MIN , INT_MAX) , INT_MIN );
    ppi dfs(TreeNode* node, int& ans) {
        ppi res = ppi( pi(node->val , node->val) , node->val );
        bool isValid = true;
        if(node->left != NULL) {
            ppi temp = dfs(node->left, ans);
            if(node->val > temp.fi.se) {
                res.fi.fi = temp.fi.fi;
                res.se += temp.se;
            }
            else
                isValid = false;
        }
        if(node->right != NULL) {
            ppi temp = dfs(node->right, ans);
            if(node->val < temp.fi.fi) {
                res.fi.se = temp.fi.se;
                res.se += temp.se;
            }
            else
                isValid = false;
        }
        if(!isValid)
            res = INVALID;
        else
            ans = max( ans , res.se );
        return res;
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};