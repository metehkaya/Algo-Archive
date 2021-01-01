class Solution {
public:
    int mctFromLeafValues(vector<int>& ar) {
        int n = ar.size();
        vector<vector<int>> mx(n,vector<int>(n));
        for( int i = 0 ; i < n ; i++ ) {
            mx[i][i] = ar[i];
            for( int j = i+1 ; j < n ; j++ )
                mx[i][j] = max( mx[i][j-1] , ar[j] );
        }
        vector<vector<int>> dp(n,vector<int>(n,0));
        for( int len = 2 ; len <= n ; len++ )
            for( int i = 0 ; i <= n-len ; i++ ) {
                int j = i+len-1;
                dp[i][j] = INT_MAX;
                for( int k = i ; k < j ; k++ )
                    dp[i][j] = min( dp[i][j] , dp[i][k] + dp[k+1][j] + mx[i][k] * mx[k+1][j] );
            }
        return dp[0][n-1];
    }
};