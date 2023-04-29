typedef long long LL;
#define mod 1000000007

class Solution {
public:
    void fillDP(vector<LL>& dp, int n, int k) {
        dp[0] = 1;
        for( int i = 1 ; i <= n ; i++ ) {
            for( int j = 1 ; j <= k ; j++ )
                if(j <= i)
                    dp[i] += dp[i-j];
            dp[i] %= mod;
        }
    }
    int countTexts(string s) {
        int n = s.length();
        vector<LL> dp3(n+1,0);
        vector<LL> dp4(n+1,0);
        fillDP(dp3,n,3);
        fillDP(dp4,n,4);
        LL ans = 1;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && s[i] == s[j])
                j++;
            int diff = j-i;
            int k = (s[i] == '7' or s[i] == '9') ? 4 : 3;
            if(k == 3)
                ans = ans*dp3[diff] % mod;
            else
                ans = ans*dp4[diff] % mod;
        }
        return ans;
    }
};
