class Solution {
public:
    const int mod = (int) 1e9+7;
    int goodBinaryStrings(int minl, int maxl, int ones, int zeroes) {
        vector<int> dp(maxl+1,0);
        dp[0] = 1;
        int ans = 0;
        for( int i = 1 ; i <= maxl ; i++ ) {
            if(i >= ones)
                dp[i] = dp[i-ones];
            if(i >= zeroes)
                dp[i] = (dp[i] + dp[i-zeroes]) % mod;
            if(i >= minl)
                ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};
