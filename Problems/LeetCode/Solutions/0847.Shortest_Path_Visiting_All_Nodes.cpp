class Solution {
public:
    int N,n;
    int dist[12][12];
    int dp[12][4096];
    vector<vector<int>> adj;
    void bfs(int src) {
        queue<int> Q;
        Q.push(src);
        dist[src][src] = 0;
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            int deg = adj[u].size();
            for( int i = 0 ; i < deg ; i++ ) {
                int v = adj[u][i];
                if(dist[src][v] != -1)
                    continue;
                Q.push(v);
                dist[src][v] = dist[src][u]+1;
            }
        }
    }
    int f(int u , int bmask) {
        if(bmask == N-1)
            return 0;
        if(dp[u][bmask] != -1)
            return dp[u][bmask];
        dp[u][bmask] = INT_MAX;
        for( int i = 0 ; i < n ; i++ )
            if((bmask & (1<<i)) == 0)
                dp[u][bmask] = min(dp[u][bmask],f(i,bmask|(1<<i))+dist[u][i]);
        return dp[u][bmask];
    }
    int shortestPathLength(vector<vector<int>>& adj) {
        this->adj = adj;
        n = adj.size();
        N = (1<<n);
        memset(dist,-1,sizeof(dist));
        for( int i = 0 ; i < n ; i++ )
            bfs(i);
        int ans = INT_MAX;
        memset(dp,-1,sizeof(dp));
        for( int i = 0 ; i < n ; i++ )
            ans = min(ans,f(i,(1<<i)));
        return ans;
    }
};