class Solution {
public:
    const int mod = (int) 1e9+7;
    int numberOfWays(int n, int x) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for( int val = 1 ; val <= n ; val++ ) {
            int mult = 1;
            for( int i = 0 ; i < x ; i++ )
                mult *= val;
            if(mult > n)
                break;
            for( int i = n ; i >= mult ; i-- )
                dp[i] = (dp[i] + dp[i-mult]) % mod;
        }
        return dp[n];
    }
};
