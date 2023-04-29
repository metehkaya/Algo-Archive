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
    int bestFreq;
    vector<int> ans;
    map<int,int> mp;
    void dfs(TreeNode* node) {
        if(node == NULL)
            return;
        int val = node->val;
        int cnt = ++mp[val];
        if(cnt > bestFreq) {
            bestFreq = cnt;
            ans.clear();
            ans.push_back(val);
        }
        else if(cnt == bestFreq)
            ans.push_back(val);
        dfs(node->left);
        dfs(node->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
};