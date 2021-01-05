class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ar) {
        int n = ar.size() , m = ar[0].size();
        int dp[n][m];
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                if(ar[i][j] == 1)
                    dp[i][j] = 0;
                else if(i == 0 && j == 0)
                    dp[i][j] = 1;
                else {
                    dp[i][j] = 0;
                    if(i > 0)
                        dp[i][j] += dp[i-1][j];
                    if(j > 0)
                        dp[i][j] += dp[i][j-1];
                }
            }
        return dp[n-1][m-1];
    }
};