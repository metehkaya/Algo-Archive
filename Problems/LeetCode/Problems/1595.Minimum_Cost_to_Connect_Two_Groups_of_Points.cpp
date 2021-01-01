class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size();
        int m = cost[0].size();
        int N = (1<<n);
        int M = (1<<m);
        int dp[N][M];
        int last1[N];
        memset(last1,-1,sizeof(last1));
        for( int i = 0 ; i < N ; i++ )
            for( int j = 0 ; j < n ; j++ )
                if((i & (1<<j)) == 0) {
                    last1[i] = j;
                    break;
                }
        int last2[M];
        memset(last2,-1,sizeof(last2));
        for( int i = 0 ; i < M ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if((i & (1<<j)) == 0) {
                    last2[i] = j;
                    break;
                }
        memset(dp,-1,sizeof(dp));
        dp[0][0] = 0;
        for( int k1 = 0 ; k1 < N ; k1++ )
            for( int k2 = 0 ; k2 < M ; k2++ ) {
                if(dp[k1][k2] == -1)
                    continue;
                int x = last1[k1];
                int y = last2[k2];
                if(x != -1) {
                    for( int i = 0 ; i < m ; i++ ) {
                        int k3 = (k1 | (1<<x));
                        int k4 = (k2 | (1<<i));
                        if(dp[k3][k4] == -1 || dp[k1][k2]+cost[x][i] < dp[k3][k4])
                            dp[k3][k4] = dp[k1][k2]+cost[x][i];
                    }
                }
                if(y != -1) {
                    for( int i = 0 ; i < n ; i++ ) {
                        int k3 = (k1 | (1<<i));
                        int k4 = (k2 | (1<<y));
                        if(dp[k3][k4] == -1 || dp[k1][k2]+cost[i][y] < dp[k3][k4])
                            dp[k3][k4] = dp[k1][k2]+cost[i][y];
                    }
                }
            }
        return dp[N-1][M-1];
    }
};