typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    int dfs(int u, int dad, vvi& adj, int& ans) {
        vi best(2,0);
        for( int i = 0 ; i < adj[u].size() ; i++ ) {
            int v = adj[u][i];
            if(v == dad)
                continue;
            int temp = dfs(v,u,adj,ans) + 1;
            if(temp > best[0]) {
                best[1] = best[0];
                best[0] = temp;
            }
            else if(temp > best[1])
                best[1] = temp;
        }
        ans = max( ans , best[0] + best[1] );
        return best[0];
    }
    int treeDiameter(vvi& edges) {
        int n = edges.size() + 1;
        vvi adj(n);
        for( int i = 0 ; i < n-1 ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        dfs(0,-1,adj,ans);
        return ans;
    }
};