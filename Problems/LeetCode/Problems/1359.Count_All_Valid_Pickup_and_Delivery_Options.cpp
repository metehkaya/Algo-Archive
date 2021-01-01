typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    const int MOD = (LL) 1e9 + 7;
    LL f(int rem, int curr, vvi& dp) {
        if(rem == 0)
            return 1;
        if(dp[rem][curr] != -1)
            return dp[rem][curr];
        dp[rem][curr] = 0;
        if(curr < rem)
            dp[rem][curr] = ( (rem-curr) * f(rem,curr+1,dp) ) % MOD;
        if(curr)
            dp[rem][curr] = ( dp[rem][curr] + curr * f(rem-1,curr-1,dp) ) % MOD;
        return dp[rem][curr];
    }
    int countOrders(int n) {
        vvi dp(n+1,vi(n+1,-1));
        return f(n,0,dp);
    }
};