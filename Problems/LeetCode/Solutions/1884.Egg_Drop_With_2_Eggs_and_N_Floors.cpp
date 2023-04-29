class Solution {
public:
    int dp[1001];
    int f(int n) {
        if(n <= 1)
            return n;
        if(dp[n] != -1)
            return dp[n];
        int mn = INT_MAX;
        for( int i = 1 ; i <= n ; i++ ) {
            int val = max(i-1,f(n-i))+1;
            mn = min(mn,val);
        }
        return dp[n] = mn;
    }
    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};