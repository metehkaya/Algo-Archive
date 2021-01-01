class Solution {
public:
    bool dfs(int node, vector<int>& mark, vector<vector<int>>& adj) {
        mark[node] = 1;
        for( int i = 0 ; i < adj[node].size() ; i++ ) {
            int to = adj[node][i];
            if(mark[to] == 1)
                return false;
            else if(!mark[to] && !dfs(to,mark,adj))
                return false;
        }
        mark[node] = 2;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        int m = (int) edges.size();
        vector<vector<int>> adj(n,vector<int>(0));
        for( int i = 0 ; i < m ; i++ ) {
            int s = edges[i][1];
            int e = edges[i][0];
            adj[s].push_back(e);
        }
        vector<int> mark(n,0);
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i])
                if(!dfs(i,mark,adj))
                    return false;
        return true;
    }
};