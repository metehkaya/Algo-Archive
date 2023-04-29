class Solution {
public:
    bool dfs(int node, int dest, vector<vector<int>>& adj, vector<int>& mark) {
        if(adj[node].size() == 0)
            return node==dest;
        mark[node] = 0;
        for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
            int to = adj[node][i];
            if(mark[to] == 0)
                return false;
            if(mark[to] != 1)
                if(!dfs(to,dest,adj,mark))
                    return false;
        }
        mark[node] = 1;
        return true;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<int> mark(n,-1);
        vector<vector<int>> adj(n);
        for( int i = 0 ; i < (int) edges.size() ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        return dfs(src, dest, adj, mark);
    }
};