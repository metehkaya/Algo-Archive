typedef long long LL;

class Solution {
public:
    static const int maxn = 100000;
    LL dp[maxn][2];
    vector<vector<int>> adj[maxn];
    LL f(int u , int k) {
        if(dp[u][k] != LLONG_MIN)
            return dp[u][k];
        LL sum = 0;
        vector<vector<LL>> scores;
        for(auto& edge : adj[u]) {
            int v = edge[0] , w = edge[1];
            LL val0 = f(v,0);
            LL val1 = f(v,1) + w;
            scores.push_back({val0,val1});
            sum += val0;
        }
        dp[u][k] = sum;
        if(k == 0)
            for(auto& score : scores)
                dp[u][k] = max(dp[u][k], sum-score[0]+score[1]);
        return dp[u][k];
    }
    LL maxScore(vector<vector<int>>& edges) {
        int n = edges.size();
        for( int i = 0 ; i < n ; i++ ) {
            dp[i][0] = dp[i][1] = LLONG_MIN;
            if(i)
                adj[edges[i][0]].push_back({i,edges[i][1]});
        }
        return f(0,0);
    }
};
