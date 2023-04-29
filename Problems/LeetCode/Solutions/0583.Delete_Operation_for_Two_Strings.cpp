class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ ) {
                int add = (s[i-1] == t[j-1]);
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+add);
            }
        return n+m-2*dp[n][m];
    }
};