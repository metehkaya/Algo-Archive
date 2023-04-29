typedef long long LL;

class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    int numberOfWays(int n) {
        vector<LL> dp(n+1);
        dp[0] = dp[2] = 1;
        for( int i = 4 ; i <= n ; i += 2 )
            for( int j = 2 ; j <= i ; j += 2 )
                dp[i] = ( dp[i] + dp[j-2] * dp[i-j] ) % MOD;
        return dp[n];
    }
};