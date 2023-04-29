class Solution {
public:
    static const int maxn = 1000;
    int t;
    int dt[maxn];
    int ft[maxn];
    int tree[maxn];
    vector<int> adj[maxn];
    int dfs(int u , int dad) {
        int deg = adj[u].size();
        dt[u] = ++t;
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i];
            if(v == dad)
                continue;
            tree[u] ^= dfs(v,u);
        }
        ft[u] = t;
        return tree[u];
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        for( int i = 0 ; i < n ; i++ )
            tree[i] = nums[i];
        for( int i = 0 ; i < n-1 ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1);
        int ans = INT_MAX;
        for( int u = 1 ; u < n ; u++ )
            for( int v = u+1 ; v < n ; v++ ) {
                int treeu = tree[u];
                int treev = tree[v];
                int tree0 = (tree[0] ^ treeu ^ treev);
                if(dt[u] <= dt[v] && ft[v] <= ft[u]) {
                    treeu ^= treev;
                    tree0 = (tree[0] ^ tree[u]);
                }
                else if(dt[v] <= dt[u] && ft[u] <= ft[v]) {
                    treev ^= treeu;
                    tree0 = (tree[0] ^ tree[v]);
                }
                int mx = max(tree0,max(treeu,treev));
                int mn = min(tree0,min(treeu,treev));
                ans = min(ans,mx-mn);
            }
        return ans;
    }
};
