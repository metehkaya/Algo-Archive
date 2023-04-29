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
    vector<vector<int>> ans;
    void dfs(TreeNode* node , int sum , vector<int>& path) {
        sum -= node->val;
        path.push_back(node->val);
        if(node->left == NULL && node->right == NULL) {
            if(sum == 0)
                ans.push_back(path);
        }
        else {
            if(node->left)
                dfs(node->left,sum,path);
            if(node->right)
                dfs(node->right,sum,path);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        if(root != NULL)
            dfs(root,targetSum,path);
        return ans;
    }
};