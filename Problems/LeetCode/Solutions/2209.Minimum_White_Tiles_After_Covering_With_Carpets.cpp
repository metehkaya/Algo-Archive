class Solution {
public:
    int minimumWhiteTiles(string s, int m, int l) {
        int n = s.length();
        vector<int> sum(n+1,0);
        for( int i = 0 ; i < n ; i++ )
            sum[i+1] = sum[i] + (s[i] - '0');
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for( int i = n-1 ; i >= 0 ; i-- ) {
            dp[i][0] = dp[i+1][0];
            int len = min(l,n-i);
            int k = i+len;
            int ones = sum[k]-sum[i];
            for( int j = 1 ; j <= m ; j++ )
                dp[i][j] = max(dp[i+1][j],dp[k][j-1]+ones);
        }
        return sum[n]-dp[0][m];
    }
};
