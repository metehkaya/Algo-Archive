typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    int minFallingPathSum(vvi& ar) {
        int n = ar.size();
        int m = ar[0].size();
        vvi dp(n, vi(m));
        for( int i = 0 ; i < m ; i++ )
            dp[0][i] = ar[0][i];
        for( int i = 1 ; i < n ; i++ ) {
            vvi mins(2, vi(2));
            mins[0][0] = mins[1][0] = INT_MAX;
            for( int j = 0 ; j < m ; j++ ) {
                if( dp[i-1][j] < mins[0][0] ) {
                    mins[1] = mins[0];
                    mins[0][0] = dp[i-1][j];
                    mins[0][1] = j;
                }
                else if( dp[i-1][j] < mins[1][0] ) {
                    mins[1][0] = dp[i-1][j];
                    mins[1][1] = j;
                }
            }
            for( int j = 0 ; j < m ; j++ ) {
                if( j == mins[0][1] )
                    dp[i][j] = mins[1][0];
                else
                    dp[i][j] = mins[0][0];
                dp[i][j] += ar[i][j];
            }
        }
        int ans = INT_MAX;
        for( int i = 0 ; i < m ; i++ )
            ans = min( ans , dp[n-1][i] );
        return ans;
    }
};