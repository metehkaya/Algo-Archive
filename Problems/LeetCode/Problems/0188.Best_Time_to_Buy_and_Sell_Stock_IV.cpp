class Solution {
public:
    const int LOW = -(1<<29);
    int maxProfit(int k, vector<int>& ar) {
        int n = ar.size();
        if(n == 0 || k == 0)
            return 0;
        int ans = 0;
        if(2*k >= n) {
            for( int i = 1 ; i < n ; i++ )
                ans += max(ar[i]-ar[i-1],0);
            return ans;
        }
        int dp[n][k+1][2];
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j <= k ; j++ )
                dp[i][j][0] = dp[i][j][1] = LOW;
        dp[0][0][0] = 0;
        dp[0][1][1] = -ar[0];
        for( int i = 1 ; i < n ; i++ )
            for( int j = 0 ; j <= k ; j++ ) {
                dp[i][j][0] = dp[i-1][j][0];
                dp[i][j][0] = max( dp[i][j][0] , dp[i-1][j][1] + ar[i] );
                dp[i][j][1] = dp[i-1][j][1];
                if(j)
                    dp[i][j][1] = max( dp[i][j][1] , dp[i-1][j-1][0] - ar[i] );
            }
        for( int j = 0 ; j <= k ; j++ )
            ans = max(ans,dp[n-1][j][0]);
        return ans;
    }
};