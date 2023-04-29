typedef long long LL;

class Solution {
public:
    static const int maxs = 1001;
    static const int mod = (int) 1e9 + 7;
    int dp[maxs];
    int val[maxs][maxs];
    int longestDecomposition(string s) {
        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        int n = s.length();
        for( int i = 0 ; i < n ; i++ ) {
            LL v = 0;
            for( int j = i ; j < n ; j++ ) {
                v = 26*v + s[j]-'a';
                v %= mod;
                val[i][j-i+1] = v;
            }
        }
        for( int k = 0 ; k < n ; k += 2 )
            if(dp[k] != -1) {
                int s = k/2 , e = n-k/2;
                dp[n] = max(dp[n],dp[k]+1);
                for( int i = 1 ; k+2*i <= n ; i++ )
                    if(val[s][i] == val[e-i][i])
                        dp[k+2*i] = max(dp[k+2*i],dp[k]+2);
            }
        return dp[n];
    }
};