typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

class Solution {
public:
    int dfs2(int node, int dad, vb& subtree, vvi& adj) {
        int ans = 0;
        for( int i = 0 ; i < adj[node].size() ; i++ ) {
            int to = adj[node][i];
            if(to != dad && subtree[to])
                ans += dfs2(to,node,subtree,adj) + 2;
        }
        return ans;
    }
    bool dfs1(int node, int dad, vb& subtree, vb& hasApple, vvi& adj) {
        subtree[node] = hasApple[node];
        for( int i = 0 ; i < adj[node].size() ; i++ ) {
            int to = adj[node][i];
            if(to != dad)
                if( dfs1(to, node, subtree, hasApple, adj) )
                    subtree[node] = true;
        }
        return subtree[node];
    }
    int minTime(int n, vvi& edges, vb& hasApple) {
        int m = edges.size();
        vvi adj(n);
        vb subtree(n,false);
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs1(0,-1,subtree,hasApple,adj);
        return dfs2(0,-1,subtree,adj);
    }
};