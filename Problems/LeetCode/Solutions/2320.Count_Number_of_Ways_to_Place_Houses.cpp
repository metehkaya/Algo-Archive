#define mod 1000000007
typedef long long LL;

class Solution {
public:
    int countHousePlacements(int n) {
        int dp[n+1][2];
        memset(dp,0,sizeof(dp));
        dp[1][0] = dp[1][1] = 1;
        for( int i = 2 ; i <= n ; i++ ) {
            dp[i][1] = dp[i-1][0];
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
        }
        LL ans = (dp[n][0] + dp[n][1]) % mod;
        ans = (ans*ans) % mod;
        return (int)ans;
    }
};
