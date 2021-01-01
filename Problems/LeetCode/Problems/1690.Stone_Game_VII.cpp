class Solution {
public:
    int stoneGameVII(vector<int>& ar) {
        int n = ar.size();
        int sum[n+1];
        sum[0] = 0;
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1] + ar[i-1];
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for( int len = 2 ; len <= n ; len++ )
            for( int i = 1 ; i <= n-len+1 ; i++ ) {
                int j = i+len-1;
                int l = sum[j] - sum[i];
                int r = sum[j-1] - sum[i-1];
                dp[i][j] = max(l-dp[i+1][j],r-dp[i][j-1]);
            }
        return dp[1][n];
    }
};