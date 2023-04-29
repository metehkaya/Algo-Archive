class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        for( int i = 1 ; i < n ; i++ ) {
            for( int j = i+1 ; j <= n ; j++ )
                dp[j] = max(dp[j],dp[i]+j-i);
            for( int j = i+3 ; j <= n ; j++ )
                dp[j] = max(dp[j],(j-i-1)*dp[i]);
        }
        return dp[n];
    }
};
