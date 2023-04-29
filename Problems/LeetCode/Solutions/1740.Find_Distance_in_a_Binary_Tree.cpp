class Solution {
public:
    vector<int> path[2];
    void dfs(TreeNode* node, int p, int q, vector<int>& v) {
        if(node->val == p)
            path[0] = v;
        else if(node->val == q)
            path[1] = v;
        if(node->left) {
            v.push_back(0);
            dfs(node->left,p,q,v);
            v.pop_back();
        }
        if(node->right) {
            v.push_back(1);
            dfs(node->right,p,q,v);
            v.pop_back();
        }
    }
    int findDistance(TreeNode* root, int p, int q) {
        if(p == q)
            return 0;
        vector<int> v;
        dfs(root,p,q,v);
        int common = 0;
        int n = path[0].size();
        int m = path[1].size();
        while(common < min(n,m) and path[0][common] == path[1][common])
            common++;
        return n+m-2*common;
    }
};
