class Solution {
public:
    int n;
    int dp[1000][3];
    const int mod = (int) 1e9+7;
    int f(int idx , int mask) {
        if(idx == n)
            return mask == 0;
        if(dp[idx][mask] != -1)
            return dp[idx][mask];
        dp[idx][mask] = 0;
        if(mask == 2)
            dp[idx][mask] = f(idx+1,0);
        else if(mask == 1)
            dp[idx][mask] = ( f(idx+1,2) + f(idx+1,1) ) % mod;
        else {
            dp[idx][mask] = ( f(idx+1,0) + f(idx+1,2) ) % mod;
            dp[idx][mask] = ( dp[idx][mask] + f(idx+1,1) ) % mod;
            dp[idx][mask] = ( dp[idx][mask] + f(idx+1,1) ) % mod;
        }
        return dp[idx][mask];
    }
    int numTilings(int n) {
        this->n = n;
        memset(dp,-1,sizeof(dp));
        return f(0,0);
    }
};