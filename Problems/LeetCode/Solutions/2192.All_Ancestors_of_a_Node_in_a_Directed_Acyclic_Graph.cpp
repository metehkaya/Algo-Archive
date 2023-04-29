class Solution {
public:
    void dfs(int u , vector<vector<int>>& adj , vector<bool>& mark) {
        mark[u] = true;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i];
            if(!mark[v])
                dfs(v,adj,mark);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int m = edges.size();
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[v].push_back(u);
        }
        vector<vector<int>> ans;
        for( int i = 0 ; i < n ; i++ ) {
            vector<bool> mark(n,false);
            dfs(i,adj,mark);
            vector<int> v;
            for( int j = 0 ; j < n ; j++ )
                if(mark[j] && i != j)
                    v.push_back(j);
            ans.push_back(v);
        }
        return ans;
    }
};
