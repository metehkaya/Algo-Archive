class Solution {
public:
    bool stoneGame(vector<int>& ar) {
        int n = ar.size();
        int dp[n][n];
        for( int i = 0 ; i < n ; i++ )
            dp[i][i] = ar[i];
        for( int len = 2 ; len <= n ; len++ )
            for( int i = 0 ; i <= n-len ; i++ ) {
                int j = i+len-1;
                dp[i][j] = max(ar[i]-dp[i+1][j],ar[j]-dp[i][j-1]);
            }
        return dp[0][n-1] > 0;
    }
};