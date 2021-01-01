class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    int distinctSubseqII(string s) {
        int n = s.length();
        s = " " + s;
        vector<int> dp(n+1);
        vector<int> last(26,-1);
        dp[0] = 1;
        for( int i = 1 ; i <= n ; i++ ) {
            int c = s[i] - 'a';
            dp[i] = 2 * dp[i-1] % MOD;
            if(last[c] != -1)
                dp[i] = ( dp[i] - dp[last[c]-1] + MOD ) % MOD;
            last[c] = i;
        }
        int ans = (dp[n] - 1 + MOD) % MOD;
        return ans;
    }
};