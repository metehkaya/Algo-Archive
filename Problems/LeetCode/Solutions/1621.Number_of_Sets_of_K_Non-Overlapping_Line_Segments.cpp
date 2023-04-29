class Solution {
public:
    int dp[1000][1000][2];
    const int mod = (int) 1e9+7;
    int numberOfSets(int n, int k) {
        dp[0][0][0] = 1;
        for( int i = 1 ; i < n ; i++ )
            for( int j = 0 ; j <= k ; j++ ) {
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % mod;
                if(j > 0) {
                    dp[i][j][1] = (dp[i-1][j-1][0] + dp[i-1][j][1]) % mod;
                    dp[i][j][1] = (dp[i][j][1] + dp[i-1][j-1][1]) % mod;
                }
            }
        return (dp[n-1][k][0] + dp[n-1][k][1]) % mod;
    }
};