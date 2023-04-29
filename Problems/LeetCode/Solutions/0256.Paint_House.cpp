class Solution {
public:
    int minCost(vector<vector<int>>& ar) {
        int n = ar.size();
        if(n == 0)
            return 0;
        int dp[n][3];
        for( int i = 0 ; i < 3 ; i++ )
            dp[0][i] = ar[0][i];
        for( int i = 1 ; i < n ; i++ )
            for( int j = 0 ; j < 3 ; j++ ) {
                dp[i][j] = INT_MAX;
                for( int k = 0 ; k < 3 ; k++ )
                    if(j != k)
                        dp[i][j] = min( dp[i][j] , dp[i-1][k] + ar[i][j] );
            }
        int ans = INT_MAX;
        for( int i = 0 ; i < 3 ; i++ )
            ans = min( ans , dp[n-1][i] );
        return ans;
    }
};