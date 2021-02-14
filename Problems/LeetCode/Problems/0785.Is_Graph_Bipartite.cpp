class Solution {
public:
    int n;
    int col[100];
    vector<vector<int>> adj;
    bool dfs(int u , int c) {
        col[u] = c;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i];
            if(col[u] == col[v])
                return false;
            if(col[v] == -1)
                if(!dfs(v,!c))
                    return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        adj = graph;
        n = adj.size();
        memset(col,-1,sizeof(col));
        for( int i = 0 ; i < n ; i++ )
            if(col[i] == -1)
                if(!dfs(i,0))
                    return false;
        return true;
    }
};