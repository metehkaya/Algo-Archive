class Solution {
public:
    void dfs(int u, int p, int& t, vector<vector<int>>& adj, vector<int>& low, vector<int>& disc, vector<bool>& mark, vector<vector<int>>& ans) {
        mark[u] = true;
        low[u] = disc[u] = ++t;
        for( int i = 0 ; i < adj[u].size() ; i++ ) {
            int v = adj[u][i];
            if(!mark[v]) {
                dfs(v,u,t,adj,low,disc,mark,ans);
                low[u] = min(low[u], low[v]);
                if(low[v] > disc[u]) {
                    vector<int>edge;
                    edge.push_back(u);
                    edge.push_back(v);
                    ans.push_back(edge);
                }
            }
            else if(v != p)
                low[u] = min(low[u], disc[v]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int m = edges.size();
        for( int i = 0 ; i < m ; i++ ) {
            int x = edges[i][0];
            int y = edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int>low(n,-1);
        vector<int>disc(n,-1);
        vector<bool>mark(n,0);
        vector<vector<int>>ans;
        int t = 0;
        dfs(0,-1,t,adj,low,disc,mark,ans);
        return ans;
    }
};