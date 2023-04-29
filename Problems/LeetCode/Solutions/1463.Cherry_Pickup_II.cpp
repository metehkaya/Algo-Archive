class Solution {
public:
    int cherryPickup(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        vector<vector<vector<int>>> dp( n , vector<vector<int>>( m , vector<int>( m , -1 ) ) );
        dp[0][0][m-1] = ar[0][0] + ar[0][m-1];
        for( int level = 1 ; level < n ; level++ )
            for( int i = 0 ; i < m ; i++ )
                for( int j = i ; j < m ; j++ ) {
                    int best = -1;
                    for( int a = -1 ; a <= 1 ; a++ )
                        for( int b = -1 ; b <= 1 ; b++ ) {
                            if( i+a < 0 || i+a >= m || j+b < 0 || j+b >= m || i+a > j+b )
                                continue;
                            best = max( best, dp[level-1][i+a][j+b] );
                        }
                    if(best != -1) {
                        dp[level][i][j] = best + ar[level][i] + ar[level][j];
                        if(i == j)
                            dp[level][i][j] -= ar[level][j];
                    }
                }
        int ans = -1;
        for( int i = 0 ; i < m ; i++ )
            for( int j = i ; j < m ; j++ )
                ans = max( ans , dp[n-1][i][j] );
        return ans;
    }
};