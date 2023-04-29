class Solution {
public:
    int maxCoins(vector<int>& v) {
        int n = v.size();
        int ar[n+2];
        ar[0] = ar[n+1] = 1;
        for( int i = 0 ; i < n ; i++ )
            ar[i+1] = v[i];
        int dp[n+2][n+2];
        memset(dp,0,sizeof(dp));
        for( int len = 3 ; len <= n+2 ; len++ )
            for( int l = 0 ; l+len <= n+2 ; l++ ) {
                int r = l+len-1;
                for( int i = l+1 ; i < r ; i++ )
                    dp[l][r] = max( dp[l][r] , dp[l][i] + dp[i][r] + ar[l]*ar[i]*ar[r] );
            }
        return dp[0][n+1];
    }
};