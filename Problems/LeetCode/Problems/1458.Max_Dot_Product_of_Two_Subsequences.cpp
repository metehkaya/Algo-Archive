class Solution {
public:
    const int SMALL = -1000000;
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int dp[n+1][m+1][2];
        memset(dp,0,sizeof(dp));
        for( int i = 0 ; i <= m ; i++ )
            dp[n][i][1] = SMALL;
        for( int i = 0 ; i <= n ; i++ )
            dp[i][m][1] = SMALL;
        for( int i = n-1 ; i >= 0 ; i-- )
            for( int j = m-1 ; j >= 0 ; j-- ) {
                dp[i][j][0] = max( dp[i][j+1][0] , dp[i+1][j][0] );
                dp[i][j][0] = max( dp[i][j][0] , dp[i+1][j+1][0]+a[i]*b[j] );
                dp[i][j][1] = max( dp[i][j+1][1] , dp[i+1][j][1] );
                dp[i][j][1] = max( dp[i][j][1] , dp[i+1][j+1][0]+a[i]*b[j] );
            }
        return dp[0][0][1];
    }
};