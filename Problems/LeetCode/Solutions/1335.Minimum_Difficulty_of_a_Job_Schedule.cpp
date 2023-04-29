typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    int minDifficulty(vi& ar, int d) {
        int n = ar.size();
        if(n < d)
            return -1;
        vii dp( d+1 , vi( n+1 , INT_MAX ) );
        dp[0][0] = 0;
        for( int day = 1 ; day <= d ; day++ )
            for( int i = day ; i <= n ; i++ ) {
                int mx = -1;
                for( int j = i-1 ; j >= 0 ; j-- ) {
                    mx = max( mx , ar[j] );
                    if( dp[day-1][j] == INT_MAX )
                        continue;
                    dp[day][i] = min( dp[day][i] , dp[day-1][j] + mx );
                }
            }
        return dp[d][n];
    }
};