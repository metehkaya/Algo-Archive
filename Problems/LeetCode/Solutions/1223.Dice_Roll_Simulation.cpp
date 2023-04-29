typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    int dieSimulator(int n, vector<int>& ar) {
        vii dp(n+1,vi(6,0));
        dp[0][0] = 1;
        for( int num = 1 ; num <= n ; num++ )
            for( int i = 0 ; i < 6 ; i++ )
                for( int cnt = 1 ; cnt <= min(num,ar[i]) ; cnt++ ) {
                    int rem = num-cnt;
                    if(rem == 0)
                        dp[num][i] = (dp[num][i] + 1) % MOD;
                    else
                        for( int j = 0 ; j < 6 ; j++ )
                            if(i != j)
                                dp[num][i] = (dp[num][i] + dp[rem][j]) % MOD;
                }
        int ans = 0;
        for( int i = 0 ; i < 6 ; i++ )
            ans = ( ans + dp[n][i] ) % MOD;
        return ans;
    }
};