#define mod 1000000007
typedef long long LL;

class Solution {
public:
    static const int maxn = 10021;
    static const int maxm = 21;
    int dp[maxn][maxm];
    int idealArrays(int n, int maxValue) {
        LL ans = 0;
        for( int i = 0 ; i < maxn ; i++ )
            dp[i][0] = 1;
        for( int i = 1 ; i < maxn ; i++ )
            for( int j = 1 ; j < maxm ; j++ )
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
        for( int val = 1 ; val <= maxValue ; val++ ) {
            LL mult = 1 , x = val;
            for( int i = 2 ; i <= 100 ; i++ ) {
                int cnt = 0;
                while(x % i == 0) {
                    x /= i;
                    cnt++;
                }
                mult *= dp[cnt+n-1][cnt];
                mult %= mod;
            }
            if(x > 1) {
                mult *= dp[1+n-1][1];
                mult %= mod;
            }
            ans = (ans+mult) % mod;
        }
        return ans;
    }
};
