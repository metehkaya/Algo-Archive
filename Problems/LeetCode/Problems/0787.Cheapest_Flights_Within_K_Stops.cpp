typedef pair<int,int> pi;
typedef vector<pi> vp;
typedef vector<vp> vpp;
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    const int BIG = (int) 1e9;
    int f(int u , int k , int dest , vpp& adj , vii& dp) {
        if(u == dest)
            return 0;
        if(k == 0)
            return BIG;
        if(dp[u][k] != -1)
            return dp[u][k];
        dp[u][k] = BIG;
        int sz = adj[u].size();
        for( int i = 0 ; i < sz ; i++ ) {
            int v = adj[u][i].first;
            int d = adj[u][i].second;
            dp[u][k] = min( dp[u][k] , f(v,k-1,dest,adj,dp) + d );
        }
        return dp[u][k];
    }
    int findCheapestPrice(int n, vii& edges, int src, int dst, int k) {
        int m = edges.size();
        vpp adj(n);
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            adj[u].push_back(pi(v,d));
        }
        vii dp(n,vi(k+2,-1));
        int ans = f(src,k+1,dst,adj,dp);
        return ans < BIG ? ans : -1;
    }
};