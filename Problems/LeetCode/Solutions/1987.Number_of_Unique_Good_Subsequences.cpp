class Solution {
public:
    int dp[2] = {0,1};
    const int mod = (int) 1e9+7;
    int numberOfUniqueGoodSubsequences(string s) {
        bool seen0 = false;
        int n = s.length() , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int k = s[i]-'0';
            if(k == 0)
                seen0 = true;
            ans = (ans + dp[k]) % mod;
            dp[k^1] = (dp[k^1] + dp[k]) % mod;
        }
        if(seen0)
            ans = (ans+1) % mod;
        return ans;
    }
};