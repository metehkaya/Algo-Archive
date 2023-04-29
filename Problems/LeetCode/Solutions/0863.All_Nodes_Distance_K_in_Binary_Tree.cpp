#define pb push_back

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int dist[501];
    vector<int> ans;
    vector<int> adj[501];
    void dfs(TreeNode* node) {
        int u = node->val;
        if(node->left != NULL) {
            int v = node->left->val;
            adj[u].pb(v);
            adj[v].pb(u);
            dfs(node->left);
        }
        if(node->right != NULL) {
            int v = node->right->val;
            adj[u].pb(v);
            adj[v].pb(u);
            dfs(node->right);
        }
    }
    void bfs(int u , int k) {
        queue<int> Q;
        memset(dist,-1,sizeof(dist));
        Q.push(u);
        dist[u] = 0;
        while(!Q.empty()) {
            u = Q.front();
            Q.pop();
            if(dist[u] == k)
                ans.pb(u);
            int deg = adj[u].size();
            for( int i = 0 ; i < deg ; i++ ) {
                int v = adj[u][i];
                if(dist[v] == -1) {
                    Q.push(v);
                    dist[v] = dist[u]+1;
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root);
        bfs(target->val,k);
        return ans;
    }
};