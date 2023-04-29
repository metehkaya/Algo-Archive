struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int check(TreeNode* node, int n, int x, bool& ans) {
        int cnt = 1;
        if(node->left) {
            int cntSt = check(node->left,n,x,ans);
            cnt += cntSt;
            if(cntSt > n/2)
                ans = true;
        }
        if(node->right) {
            int cntSt = check(node->right,n,x,ans);
            cnt += cntSt;
            if(cntSt > n/2)
                ans = true;
        }
        return cnt;
    }
    bool dfsFindNode(TreeNode* node, int n, int x, bool& ans) {
        if(node->val == x) {
            int st = check(node,n,x,ans);
            if(st <= n/2)
                ans = true;
            return true;
        }
        if(node->left && dfsFindNode(node->left,n,x,ans))
            return true;
        if(node->right && dfsFindNode(node->right,n,x,ans))
            return true;
        return false;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        bool ans = false;
        dfsFindNode(root,n,x,ans);
        return ans;
    }
};