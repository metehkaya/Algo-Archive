class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for( int i = 0 ; i <= n ; i++ )
            dp[i][0] = 1;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= i ; j++ )
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        return dp[n];
    }
};