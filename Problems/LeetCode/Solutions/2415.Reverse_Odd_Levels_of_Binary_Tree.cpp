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
    vector<vector<TreeNode*>> nodes;
    void dfs(TreeNode* node , int lvl) {
        if(nodes.size() == lvl)
            nodes.push_back(vector<TreeNode*>{});
        nodes[lvl].push_back(node);
        if(node->left != NULL) {
            dfs(node->left,lvl+1);
            dfs(node->right,lvl+1);
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root,0);
        for( int k = 1 ; k < nodes.size() ; k += 2 ) {
            int sz = nodes[k].size();
            for( int i = 0 ; i < sz/2 ; i++ )
                swap(nodes[k][i]->val,nodes[k][sz-1-i]->val);
        }
        return root;
    }
};
