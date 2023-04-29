class Solution {
public:
    vector<TreeNode*> ans;
    map<string,int> mp;
    string dfs(TreeNode* node) {
        if(node == NULL)
            return "N";
        string l = dfs(node->left);
        string r = dfs(node->right);
        string s = l+","+r+","+to_string(node->val);
        if(++mp[s] == 2)
            ans.push_back(node);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
