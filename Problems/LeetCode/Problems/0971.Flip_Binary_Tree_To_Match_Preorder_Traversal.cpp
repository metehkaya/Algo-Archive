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
    bool dfs(TreeNode* node , int& id , vector<int>& v , vector<int>& ans) {
        if(v[id] != node->val)
            return false;
        id++;
        bool res = true;
        if(node->left and node->right) {
            if(node->left->val == v[id]) {
                if(!dfs(node->left,id,v,ans))
                    res = false;
                else
                    res = dfs(node->right,id,v,ans);
            }
            else {
                ans.push_back(node->val);
                if(!dfs(node->right,id,v,ans))
                    res = false;
                else
                    res = dfs(node->left,id,v,ans);
            }
        }
        else if(node->left)
            res = dfs(node->left,id,v,ans);
        else if(node->right)
            res = dfs(node->right,id,v,ans);
        return res;
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& v) {
        int id = 0;
        vector<int> ans;
        bool ok = dfs(root,id,v,ans);
        if(!ok) {
            ans.clear();
            ans.push_back(-1);
        }
        return ans;
    }
};