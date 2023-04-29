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
    int depth;
    vector<int> empty;
    vector<vector<int>> tree;
    void dfs(TreeNode* node , int lvl) {
        if(node == NULL)
            return;
        if(lvl == depth)
            depth++ , tree.push_back(empty);
        tree[lvl].push_back(node->val);
        dfs(node->left,lvl+1);
        dfs(node->right,lvl+1);
    }
    bool isEvenOddTree(TreeNode* root) {
        dfs(root,0);
        for( int lvl = 0 ; lvl < depth ; lvl++ ) {
            int sz = tree[lvl].size();
            for( int i = 0 ; i < sz ; i++ )
                if(tree[lvl][i]%2 == lvl%2)
                    return false;
            if(lvl%2) {
                for( int i = 1 ; i < sz ; i++ )
                    if(tree[lvl][i] >= tree[lvl][i-1])
                        return false;
            }
            else {
                for( int i = 1 ; i < sz ; i++ )
                    if(tree[lvl][i] <= tree[lvl][i-1])
                        return false;
            }
        }
        return true;
    }
};