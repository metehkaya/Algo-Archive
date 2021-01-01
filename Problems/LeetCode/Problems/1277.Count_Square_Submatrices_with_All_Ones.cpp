typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    int countSquares(vvi& ar) {
        int n = ar.size();
        int m = ar[0].size();
        vvi dp(n,vi(m,0));
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if( ar[i][j] == 1 ) {
                    if(i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min( dp[i-1][j-1] , min( dp[i-1][j] , dp[i][j-1] ) ) + 1;
                    ans += dp[i][j];
                }
        return ans;
    }
};