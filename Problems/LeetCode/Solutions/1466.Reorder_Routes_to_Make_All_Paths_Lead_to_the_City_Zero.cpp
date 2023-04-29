typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

class Solution {
public:
    int dfs( int node , int dad , vvpi& adj ) {
        int res = 0;
        for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
            int to = adj[node][i].first;
            if(to == dad)
                continue;
            res += dfs( to , node , adj ) + adj[node][i].second;
        }
        return res;
    }
    int minReorder(int n, vii& edges) {
        vvpi adj(n);
        int m = edges.size();
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back( pi( v,1 ) );
            adj[v].push_back( pi( u,0 ) );
        }
        return dfs(0,-1,adj);
    }
};