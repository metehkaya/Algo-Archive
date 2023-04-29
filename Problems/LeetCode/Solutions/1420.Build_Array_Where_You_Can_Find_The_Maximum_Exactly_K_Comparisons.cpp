typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

class Solution {
public:
    const int MOD = 1000000007;
    int numOfArrays(int n, int m, int k) {
        if(k > n || k > m || k == 0)
            return 0;
        vvvi dp(n,vvi(k,vi(m,0)));
        vvvi dpSum(n,vvi(k,vi(m,0)));
        for( int i = 0 ; i < m ; i++ )
            dp[0][0][i] = 1 , dpSum[0][0][i] = i+1;
        for( int i = 1 ; i < n ; i++ )
            for( int j = 0 ; j < k ; j++ ) {
                for( int l = 0 ; l < m ; l++ )
                    dp[i][j][l] = ( (LL) dp[i-1][j][l] * (l+1) ) % MOD;
                if(j)
                    for( int l = 1 ; l < m ; l++ )
                        dp[i][j][l] = ( dp[i][j][l] + dpSum[i-1][j-1][l-1] ) % MOD;
                dpSum[i][j][0] = dp[i][j][0];
                for( int l = 1 ; l < m ; l++ )
                    dpSum[i][j][l] = ( dpSum[i][j][l-1] + dp[i][j][l] ) % MOD;
            }
        return dpSum[n-1][k-1][m-1];
    }
};