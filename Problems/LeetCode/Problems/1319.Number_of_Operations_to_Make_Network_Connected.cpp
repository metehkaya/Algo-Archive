class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& mark) {
        mark[u] = true;
        for( int i = 0 ; i < (int) adj[u].size() ; i++ ) {
            int v = adj[u][i];
            if(!mark[v])
                dfs(v, adj, mark);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cnt = 0;
        int edges = (int) connections.size();
        if(edges < n-1)
            return -1;
        vector<bool> mark(n, false);
        vector<vector<int>> adj(n, vector<int>());
        for( int i = 0 ; i < edges ; i++ ) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for( int i = 0 ; i < n ; i++ ) {
            if(!mark[i]) {
                cnt++;
                dfs(i, adj, mark);
            }
        }
        return cnt-1;
    }
};