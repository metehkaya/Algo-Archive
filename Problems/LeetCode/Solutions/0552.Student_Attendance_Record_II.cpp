class Solution {
public:
    const int mod = (int)1e9+7;
    static const int maxn = 100001;
    int dp[maxn][3][2];
    int f(int n , int l , bool a) {
        if(n == 0)
            return 1;
        if(dp[n][l][a] != -1)
            return dp[n][l][a];
        dp[n][l][a] = f(n-1,0,a);
        if(!a)
            dp[n][l][a] = (dp[n][l][a] + f(n-1,0,true)) % mod;
        if(l < 2)
            dp[n][l][a] = (dp[n][l][a] + f(n-1,l+1,a)) % mod;
        return dp[n][l][a];
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n,0,0);
    }
};
