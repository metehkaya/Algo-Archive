class Solution {
public:
    const int mod = 1e9+7;
    long long dp[3][2][2];
    int stringCount(int n) {
        dp[0][0][0] = 1;
        for( int t = 0 ; t < n ; t++ ) {
            long long dp_new[3][2][2];
            memset(dp_new,0,sizeof(dp_new));
            for( int i = 0 ; i < 3 ; i++ )
                for( int j = 0 ; j < 2 ; j++ )
                    for( int k = 0 ; k < 2 ; k++ ) {
                        dp_new[i][j][k] = (dp_new[i][j][k] + 23*dp[i][j][k]) % mod;
                        dp_new[min(i+1,2)][j][k] = (dp_new[min(i+1,2)][j][k] + dp[i][j][k]) % mod;
                        dp_new[i][min(j+1,1)][k] = (dp_new[i][min(j+1,1)][k] + dp[i][j][k]) % mod;
                        dp_new[i][j][min(k+1,1)] = (dp_new[i][j][min(k+1,1)] + dp[i][j][k]) % mod;
                    }
            swap(dp,dp_new);
        }
        return dp[2][1][1];
    }
};
