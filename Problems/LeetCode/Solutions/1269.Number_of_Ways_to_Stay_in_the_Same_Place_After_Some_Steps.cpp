class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    int numWays(int steps, int n) {
        n = min(n,steps+1);
        vector<vector<int>> dp(steps+1,vector<int>(n,0));
        dp[0][0] = 1;
        for( int s = 1 ; s <= steps ; s++ )
            for( int i = 0 ; i < n ; i++ ) {
                dp[s][i] = dp[s-1][i];
                if(i-1 >= 0)
                    dp[s][i] = ( dp[s][i] + dp[s-1][i-1] ) % MOD;
                if(i+1 <= n-1)
                    dp[s][i] = ( dp[s][i] + dp[s-1][i+1] ) % MOD;
            }
        return dp[steps][0];
    }
};