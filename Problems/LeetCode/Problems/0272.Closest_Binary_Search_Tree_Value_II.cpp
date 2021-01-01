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
    void dfs(TreeNode* node , vector<int>& v) {
        if(node->left)
            dfs(node->left,v);
        v.push_back(node->val);
        if(node->right)
            dfs(node->right,v);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> v,ans;
        if(k == 0)
            return ans;
        dfs(root,v);
        int n = v.size();
        int r = 0;
        while(r < n && v[r] < target)
            r++;
        int l = r-1;
        while(k--) {
            double cl = (1ll << 40);
            double cr = (1ll << 40);
            if(l >= 0)
                cl = target - v[l];
            if(r < n)
                cr = v[r] - target;
            if(cl <= cr)
                ans.push_back(v[l--]);
            else
                ans.push_back(v[r++]);
        }
        return ans;
    }
};