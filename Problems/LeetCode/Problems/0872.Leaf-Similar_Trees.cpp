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
        bool isLeaf = true;
        if(node->left != NULL) {
            isLeaf = false;
            dfs(node->left, v);
        }
        if(node->right != NULL)  {
            isLeaf = false;
            dfs(node->right, v);
        }
        if(isLeaf)
            v.push_back(node->val);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        dfs(root1,v1);
        dfs(root2,v2);
        if(v1.size() != v2.size())
            return false;
        int n = v1.size();
        for( int i = 0 ; i < n ; i++ )
            if( v1[i] != v2[i] )
                return false;
        return true;
    }
};