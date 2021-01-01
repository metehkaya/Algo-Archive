typedef pair<int,int> pi;

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
    void dfs(TreeNode* root , int x , int y , map<int,vector<pi>>& vals) {
        vals[x].push_back(pi(y,root->val));
        if(root->left != NULL)
            dfs(root->left,x-1,y+1,vals);
        if(root->right != NULL)
            dfs(root->right,x+1,y+1,vals);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pi>> vals;
        dfs(root,0,0,vals);
        vector<vector<int>> ans;
        for( auto it = vals.begin() ; it != vals.end() ; it++ ) {
            vector<pi> v = it->second;
            vector<int> add;
            sort(v.begin(),v.end());
            for( int i = 0 ; i < (int) v.size() ; i++ )
                add.push_back(v[i].second);
            ans.push_back(add);
        }
        return ans;
    }
};