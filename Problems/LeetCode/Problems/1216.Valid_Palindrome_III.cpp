class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n));
        for( int len = 1 ; len <= n ; len++ )
            for( int i = 0 ; i <= n-len ; i++ ) {
                int j = i+len-1;
                if(len == 1)
                    dp[i][j] = 0;
                else if(len == 2)
                    dp[i][j] = (s[i] != s[j]);
                else {
                    dp[i][j] = min( dp[i][j-1] , dp[i+1][j] ) + 1;
                    if(s[i] == s[j])
                        dp[i][j] = min( dp[i][j] , dp[i+1][j-1] );
                }
            }
        return dp[0][n-1] <= k;
    }
};