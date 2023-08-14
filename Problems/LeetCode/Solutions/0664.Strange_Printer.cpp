class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for( int i = 0 ; i < n ; i++ )
            dp[i][i] = 1;
        for( int len = 2 ; len <= n ; len++ )
            for( int i = 0 ; i <= n-len ; i++ ) {
                int j = i+len-1;
                dp[i][j] = dp[i][j-1]+1;
                for( int k = i ; k < j ; k++ )
                    if(s[j] == s[k]) {
                        if(k+1 <= j-1)
                            dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j-1]);
                        else
                            dp[i][j] = min(dp[i][j],dp[i][k]);
                    }
            }
        return dp[0][n-1];
    }
};
