class Solution {
public:
    static const int maxn = 15;
    static const int maxb = (1<<maxn);
    vector<vector<int>> adj[maxn];
    int dp[maxb][maxn];
    int f(int bmask , int u , int k) {
        if(k == 0)
            return dp[bmask][u] = 0;
        if(dp[bmask][u] != -1)
            return dp[bmask][u];
        dp[bmask][u] = INT_MIN;
        for(auto e : adj[u]) {
            int v = e[0] , w = e[1];
            if(bmask & (1<<v))
                continue;
            int bmask_new = (bmask | (1<<v));
            int val = f(bmask_new,v,k-1);
            if(val != INT_MIN)
                dp[bmask][u] = max(dp[bmask][u],val+w);
        }
        return dp[bmask][u];
    }
    int maximumCost(int n, vector<vector<int>>& edges, int k) {
        if(k+1 > n)
            return -1;
        for(auto& e : edges) {
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        int ans = INT_MIN;
        memset(dp,-1,sizeof(dp));
        for( int i = 0 ; i < n ; i++ )
            ans = max(ans,f((1<<i),i,k));
        return ans == INT_MIN ? -1 : ans;
    }
};
