class Solution {
public:
    int cnt[100];
    int G[100][100];
    int maximalNetworkRank(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            cnt[u]++,cnt[v]++;
            G[u][v]++;
            G[v][u]++;
        }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                ans = max(ans,cnt[i]+cnt[j]-G[i][j]);
        return ans;
    }
};