class Solution {
public:
    static const int maxn = 200000;
    bool mark[maxn];
    vector<int> adj[maxn];
    void dfs(int u) {
        if(mark[u])
            return;
        mark[u] = true;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i];
            dfs(v);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        int m = edges.size();
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(start);
        return mark[end];
    }
};