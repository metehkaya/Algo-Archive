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
        if(node == NULL)
            return;
        dfs(node->left,v);
        v.push_back(node->val);
        dfs(node->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans,v1,v2;
        dfs(root1,v1);
        dfs(root2,v2);
        int i = 0 , j = 0;
        int n = v1.size();
        int m = v2.size();
        while(i < n && j < m)
            if(v1[i] <= v2[j])
                ans.push_back(v1[i++]);
            else
                ans.push_back(v2[j++]);
        while(i < n)
            ans.push_back(v1[i++]);
        while(j < m)
            ans.push_back(v2[j++]);
        return ans;
    }
};