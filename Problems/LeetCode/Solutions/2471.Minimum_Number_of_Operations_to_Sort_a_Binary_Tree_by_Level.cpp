struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    void dfs(TreeNode* node, vector<vector<pi>>& values, int lvl) {
        if(node == NULL)
            return;
        if(lvl == values.size())
            values.pb(vector<pi>({pi(node->val,0)}));
        else
            values[lvl].pb(pi(node->val,values[lvl].size()));
        dfs(node->left, values, lvl+1);
        dfs(node->right, values, lvl+1);
    }
    int minimumOperations(TreeNode* root) {
        vector<vector<pi>> values;
        dfs(root,values,0);
        int ans = 0;
        for(auto v : values) {
            sort(v.begin(), v.end());
            int n = v.size();
            vector<int> g(n);
            vector<bool> mark(n,false);
            for( int i = 0 ; i < n ; i++ )
                g[v[i].se] = i;
            for( int i = 0 ; i < n ; i++ )
                if(!mark[i]) {
                    int u = i , len = 0;
                    while(!mark[u]) {
                        mark[u] = true;
                        u = g[u];
                        len++;
                    }
                    ans += len-1;
                }
        }
        return ans;
    }
};
