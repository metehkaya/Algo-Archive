class Solution {
public:
    vector<long long> v;
    void dfs(TreeNode* node , int lvl) {
        if(node == NULL)
            return;
        if(lvl == v.size())
            v.push_back(node->val);
        else
            v[lvl] += node->val;
        dfs(node->left,lvl+1);
        dfs(node->right,lvl+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        dfs(root,0);
        sort(v.begin(),v.end(),greater<>());
        return (k > v.size()) ? -1 : v[k-1];
    }
};
