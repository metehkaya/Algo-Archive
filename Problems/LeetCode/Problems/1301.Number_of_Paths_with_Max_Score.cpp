typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    vi pathsWithMaxScore(vector<string>& ar) {
        int n = ar.size();
        int m = ar[0].length();
        vvvi dp( n , vvi( m , vi(2) ) );
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                if(i == 0 && j == 0)
                    dp[i][j][0] = 0 , dp[i][j][1] = 1;
                else if(ar[i][j] == 'X')
                    dp[i][j][0] = dp[i][j][1] = -1;
                else {
                    dp[i][j][0] = dp[i][j][1] = -1;
                    if(i > 0 && dp[i-1][j][0] != -1)
                        dp[i][j] = dp[i-1][j];
                    if(j > 0 && dp[i][j-1][0] != -1) {
                        if(dp[i][j-1][0] > dp[i][j][0])
                            dp[i][j] = dp[i][j-1];
                        else if(dp[i][j-1][0] == dp[i][j][0])
                            dp[i][j][1] = ( dp[i][j][1] + dp[i][j-1][1] ) % MOD;
                    }
                    if(i > 0 && j > 0 && dp[i-1][j-1][0] != -1) {
                        if(dp[i-1][j-1][0] > dp[i][j][0])
                            dp[i][j] = dp[i-1][j-1];
                        else if(dp[i-1][j-1][0] == dp[i][j][0])
                            dp[i][j][1] = ( dp[i][j][1] + dp[i-1][j-1][1] ) % MOD;
                    }
                    if(dp[i][j][0] != -1 && ar[i][j] != 'S')
                        dp[i][j][0] += ar[i][j] - '0';
                }
            }
        vector<int> ans = dp[n-1][m-1];
        if(ans[0] == -1)
            ans[0] = ans[1] = 0;
        return ans;
    }
};