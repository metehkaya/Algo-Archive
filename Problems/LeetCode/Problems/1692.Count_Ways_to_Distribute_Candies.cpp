class Solution {
public:
    const int MOD = (int) 1e9+7;
    int waysToDistribute(int n, int k) {
        int dp[n+1][k+1];
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= k ; j++ ) {
                dp[i][j] = dp[i-1][j-1];
                int add = (long long) j * dp[i-1][j] % MOD;
                dp[i][j] = (dp[i][j] + add) % MOD;
            }
        return dp[n][k];
    }
};