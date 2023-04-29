#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    const int BIG = (1<<30);
    int minCost(int maxt, vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        int m = edges.size();
        vector<vector<pi>> adj(n);
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            int len = edges[i][2];
            adj[u].pb(pi(v,len));
            adj[v].pb(pi(u,len));
        }
        vector<vector<int>> dp(maxt+1,vector<int>(n,BIG));
        dp[0][0] = cost[0];
        for( int t = 0 ; t <= maxt ; t++ )
            for( int u = 0 ; u < n ; u++ )
                if(dp[t][u] != BIG) {
                    int deg = adj[u].size();
                    for( int i = 0 ; i < deg ; i++ ) {
                        int v = adj[u][i].fi;
                        int add = adj[u][i].se;
                        int t2 = t+add;
                        if(t2 <= maxt)
                            dp[t2][v] = min(dp[t2][v],dp[t][u]+cost[v]);
                    }
                }
        int ans = BIG;
        for( int i = 0 ; i <= maxt ; i++ )
            ans = min(ans,dp[i][n-1]);
        return (ans == BIG) ? -1 : ans;
    }
};