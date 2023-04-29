class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& ar) {
        int n = ar.size();
        vector<int> dp(n);
        for( int i = 0 ; i < n ; i++ )
            dp[i] = ar[0][i];
        for( int i = 1 ; i < n ; i++ ) {
            vector<int> old = dp;
            for( int j = 0 ; j < n ; j++ ) {
                dp[j] = old[j];
                if(j > 0)
                    dp[j] = min( dp[j] , old[j-1] );
                if(j < n-1)
                    dp[j] = min( dp[j] , old[j+1] );
                dp[j] += ar[i][j];
            }
        }
        int ans = INT_MAX;
        for( int i = 0 ; i < n ; i++ )
            ans = min( ans , dp[i] );
        return ans;
    }
};