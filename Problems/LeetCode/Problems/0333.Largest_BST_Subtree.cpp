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
    int dfs(TreeNode* node , int& mn , int& mx , int& ans) {
        mn = mx = node->val;
        int cnt = 1;
        bool isLeft = true;
        if(node->left) {
            int newMn,newMx;
            int add = dfs(node->left,newMn,newMx,ans);
            mn = min(mn,newMn);
            mx = max(mx,newMx);
            if(add == 0 || newMx >= node->val)
                isLeft = false;
            else
                cnt += add;
        }
        bool isRight = true;
        if(node->right) {
            int newMn,newMx;
            int add = dfs(node->right,newMn,newMx,ans);
            mn = min(mn,newMn);
            mx = max(mx,newMx);
            if(add == 0 || newMn <= node->val)
                isRight = false;
            else
                cnt += add;
        }
        if(isLeft && isRight)
            ans = max(ans,cnt);
        else
            cnt = 0;
        return cnt;
    }
    int largestBSTSubtree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ans = 0 , mn , mx;
        dfs(root,mn,mx,ans);
        return ans;
    }
};