class Solution {
public:
    void dfs(int u , vector<bool>& mark , vector<vector<int>>& adj) {
        mark[u] = true;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i];
            if(!mark[v])
                dfs(v,mark,adj);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int m = edges.size();
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        vector<bool> mark(n,false);
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i]) {
                ans++;
                dfs(i,mark,adj);
            }
        return ans;
    }
};