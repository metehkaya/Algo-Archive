#define mod 1000000007

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int diff = abs(startPos-endPos);
        if(k%2 != diff%2 or diff > k)
            return 0;
        int m = (k-diff)/2;
        vector<int> dp(m+1,0);
        dp[0] = 1;
        for( int i = 1 ; i <= k ; i++ ) {
            vector<int> old = dp;
            dp[0] = 1;
            for( int j = 1 ; j <= m ; j++ )
                dp[j] = (old[j-1] + old[j]) % mod;
        }
        return dp[m];
    }
};
