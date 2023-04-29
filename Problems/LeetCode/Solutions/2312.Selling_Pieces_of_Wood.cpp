class Solution {
public:
    long long sellingWood(int n, int m, vector<vector<int>>& ar) {
        long long dp[n+1][m+1];
        memset(dp,0LL,sizeof(dp));
        for( int i = 0 ; i < ar.size() ; i++ )
            dp[ar[i][0]][ar[i][1]] = ar[i][2];
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ ) {
                dp[i][j] = max(dp[i][j],max(dp[i][j-1],dp[i-1][j]));
                for( int k = 1 ; k < i ; k++ )
                    dp[i][j] = max(dp[i][j],dp[k][j]+dp[i-k][j]);
                for( int k = 1 ; k < j ; k++ )
                    dp[i][j] = max(dp[i][j],dp[i][k]+dp[i][j-k]);
            }
        return dp[n][m];
    }
};
