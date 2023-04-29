typedef long long LL;

class Solution {
public:
    const int mod = (int) 1e9+7;
    const static int maxn = 1001;
    LL dp[maxn][maxn];
    int rearrangeSticks(int n, int k) {
        dp[0][0] = 1;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= k ; j++ )
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]*(i-1)) % mod;
        return (int) dp[n][k];
    }
};