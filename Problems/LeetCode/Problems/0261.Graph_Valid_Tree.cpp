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
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        if(m != n-1)
            return false;
        vector<bool> mark(n,false);
        vector<vector<int>> adj(n);
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,mark,adj);
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i])
                return false;
        return true;
    }
};