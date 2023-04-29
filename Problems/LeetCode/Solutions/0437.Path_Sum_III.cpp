typedef long long LL;

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
    void f(TreeNode* node , LL sum , int t , int& ans , map<LL,int>& cnt) {
        sum += node->val;
        ans += cnt[sum-t];
        cnt[sum]++;
        if(node->left)
            f(node->left,sum,t,ans,cnt);
        if(node->right)
            f(node->right,sum,t,ans,cnt);
        cnt[sum]--;
    }
    int pathSum(TreeNode* root, int t) {
        int ans = 0;
        map<LL,int> cnt;
        cnt[0] = 1;
        if(root)
            f(root,0,t,ans,cnt);
        return ans;
    }
};
