class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = 1;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(i+j) {
                    if(i)
                        dp[i][j] += dp[i-1][j];
                    if(j)
                        dp[i][j] += dp[i][j-1];
                }
        return dp[n-1][m-1];
    }
};