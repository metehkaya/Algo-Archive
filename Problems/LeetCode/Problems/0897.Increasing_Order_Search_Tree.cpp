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
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        dfs(root,v);
        root = new TreeNode(v[0]);
        TreeNode* node = root;
        for( int i = 1 ; i < v.size() ; i++ ) {
            node->right = new TreeNode(v[i]);
            node = node->right;
        }
        return root;
    }
};