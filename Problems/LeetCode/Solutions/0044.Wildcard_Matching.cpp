class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        if(m == 0) {
            bool ans = true;
            for( int i = 0 ; i < n ; i++ )
                if(p[i] != '*')
                    ans = false;
            return ans;
        }
        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
        vector<vector<bool>> dp2(n+1, vector<bool>(m+1,false));
        dp[n][m] = true;
        for( int i = 0 ; i <= m ; i++ )
            dp2[n][i] = true;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            if(p[i] == '*')
                dp2[i][m] = dp[i][m] = dp[i+1][m];
            for( int j = m-1 ; j >= 0 ; j-- ) {
                if(p[i] == '*')
                    dp[i][j] = dp2[i+1][j];
                else if(p[i] == '?')
                    dp[i][j] = dp[i+1][j+1];
                else
                    dp[i][j] = ( p[i] == s[j] && dp[i+1][j+1] );
                dp2[i][j] = dp[i][j] || dp2[i][j+1];
            }
        }
        return dp[0][0];
    }
};