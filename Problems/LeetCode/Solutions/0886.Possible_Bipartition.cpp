class Solution {
public:
    void dfs(int u, int color, vector<vector<int>>& adj, vector<int>& col) {
        col[u] = color;
        for( int i = 0 ; i < adj[u].size() ; i++ ) {
            int v = adj[u][i];
            if(col[v] != -1)
                continue;
            dfs(v, color^1, adj, col);
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int m = edges.size();
        for( int i = 0 ; i < m ; i++ ) {
            int x = edges[i][0] - 1;
            int y = edges[i][1] - 1;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> col(n,-1);
        for( int i = 0 ; i < n ; i++ )
            if( col[i] == -1 )
                dfs( i , 0 , adj , col );
        bool ans = true;
        for( int i = 0 ; i < n && ans ; i++ )
            for( int j = 0 ; j < adj[i].size() ; j++ )
                if( col[i] == col[adj[i][j]] ) {
                    ans = false;
                    break;
                }
        return ans;
    }
};