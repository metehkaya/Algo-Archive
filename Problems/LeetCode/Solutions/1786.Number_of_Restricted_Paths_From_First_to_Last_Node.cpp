#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    struct st {
        bool operator()(const pi &x , const pi &y) {
            return x.se > y.se;
        }
    };
    const int mod = (int) 1e9+7;
    static const int maxn = 20001;
    int m;
    int dp[maxn];
    int dist[maxn];
    bool mark[maxn];
    vector<pi> adj[maxn];
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        m = edges.size();
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            adj[u].pb(pi(v,d));
            adj[v].pb(pi(u,d));
        }
        dp[n] = 1;
        for( int i = 1 ; i < n ; i++ )
            dist[i] = INT_MAX;
        priority_queue<pi, vector<pi>, st> heap;
        heap.push(pi(n,0));
        while(!heap.empty()) {
            pi temp = heap.top();
            heap.pop();
            int u = temp.fi;
            if(mark[u])
                continue;
            mark[u] = true;
            int d = temp.se;
            int deg = adj[u].size();
            for( int i = 0 ; i < deg ; i++ ) {
                int v = adj[u][i].fi;
                int d2 = d + adj[u][i].se;
                if(d2 < dist[v]) {
                    dist[v] = d2;
                    heap.push(pi(v,d2));
                }
                else if(dist[v] < dist[u])
                    dp[u] = (dp[u] + dp[v]) % mod;
            }
        }
        return dp[1];
    }
};