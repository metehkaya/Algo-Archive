class Solution {
public:
    void dfs(int u , int& cnt , vector<vector<int>>& adj , vector<bool>& mark) {
        cnt++;
        mark[u] = true;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i];
            if(!mark[v])
                dfs(v,cnt,adj,mark);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> adj(n);
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long ans = 0;
        long long sum = 0;
        vector<bool> mark(n,false);
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i]) {
                int cnt = 0;
                dfs(i,cnt,adj,mark);
                ans += sum*cnt;
                sum += cnt;
            }
        return ans;
    }
};
