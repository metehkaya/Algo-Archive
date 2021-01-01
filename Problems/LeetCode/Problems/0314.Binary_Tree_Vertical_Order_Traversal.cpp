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
    map< int , map< int , vector<int> > > nodes;
    void dfs(TreeNode* node , int k , int lvl) {
        if(node == NULL)
            return;
        nodes[k][lvl].push_back(node->val);
        dfs(node->left,k-1,lvl+1);
        dfs(node->right,k+1,lvl+1);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root,0,0);
        for(auto it : nodes) {
            vector<int> add;
            map<int,vector<int>> mp = it.second;
            for(auto it2 : mp) {
                vector<int> v = it2.second;
                for( int i = 0 ; i < v.size() ; i++ )
                    add.push_back(v[i]);
            }
            ans.push_back(add);
        }
        return ans;
    }
};