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
    int depth = 0;
    vector<TreeNode*> chain;
    TreeNode* dfs(TreeNode* node , TreeNode* u , int d) {
        if(node == u) {
            if(depth == d)
                return NULL;
            return chain[d];
        }
        if(depth == d)
            depth++ , chain.push_back(node);
        else
            chain[d] = node;
        if(node->right) {
            TreeNode* res = dfs(node->right,u,d+1);
            if(res)
                return res;
        }
        if(node->left) {
            TreeNode* res = dfs(node->left,u,d+1);
            if(res)
                return res;
        }
        return NULL;
    }
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        return dfs(root,u,0);
    }
};