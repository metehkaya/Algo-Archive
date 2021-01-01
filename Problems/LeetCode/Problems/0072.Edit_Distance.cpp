class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp( n+1 , vector<int>(m+1) );
        for( int i = 0 ; i <= n ; i++ )
            dp[i][m] = n-i;
        for( int i = 0 ; i <= m ; i++ )
            dp[n][i] = m-i;
        for( int i = n-1 ; i >= 0 ; i-- )
            for( int j = m-1 ; j >= 0 ; j-- ) {
                dp[i][j] = min( dp[i+1][j] , dp[i][j+1] ) + 1;
                dp[i][j] = min( dp[i][j] , dp[i+1][j+1] + ( s1[i] != s2[j] ) );
            }
        return dp[0][0];
    }
};