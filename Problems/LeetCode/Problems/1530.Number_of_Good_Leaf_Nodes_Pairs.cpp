typedef vector<int> vi;
typedef vector<vi> vii;

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
    void dfs(TreeNode* node , int dad , int& n , vii& adj) {
        int id = n++;
        adj.resize(n);
        if(dad != -1)
            adj[id].push_back(dad);
        if(node->left) {
            adj[id].push_back(n);
            dfs(node->left,id,n,adj);
        }
        if(node->right) {
            adj[id].push_back(n);
            dfs(node->right,id,n,adj);
        }
    }
    int solve(int u , int dad , int d , vii& adj) {
        int res = 0;
        if(u != 0 && dad != -1 && adj[u].size() == 1)
            res = 1;
        if(d == 0)
            return res;
        for( int i = 0 ; i < adj[u].size() ; i++ )
            if(dad != adj[u][i])
                res += solve(adj[u][i],u,d-1,adj);
        return res;
    }
    int countPairs(TreeNode* root, int d) {
        int n = 0;
        vii adj;
        dfs(root,-1,n,adj);
        int ans = 0;
        for( int i = 1 ; i < n ; i++ )
            if(adj[i].size() == 1)
                ans += solve(i,-1,d,adj);
        return ans/2;
    }
};