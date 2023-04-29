class Solution {
public:
    int dp[1000][1001];
    int sum[1000][1001];
    const int mod = (int) 1e9+7;
    int f(int i , int l , int r) {
        l = max(l,0);
        int val = sum[i][r];
        if(l > 0)
            val = (val - sum[i][l-1] + mod) % mod;
        return val;
    }
    int kInversePairs(int n, int k) {
        dp[0][0] = 1;
        for( int j = 0 ; j <= k ; j++ )
            sum[0][j] = 1;
        for( int i = 1 ; i < n ; i++ ) {
            for( int j = 0 ; j <= k ; j++ )
                dp[i][j] = (dp[i][j] + f(i-1,j-i,j)) % mod;
            sum[i][0] = dp[i][0];
            for( int j = 1 ; j <= k ; j++ )
                sum[i][j] = (sum[i][j-1] + dp[i][j]) % mod;
        }
        return dp[n-1][k];
    }
};