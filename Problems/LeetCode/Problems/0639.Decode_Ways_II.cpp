typedef long long LL;

class Solution {
public:
    const LL mod = (LL) 1e9 + 7;
    vector<int> proc(char c) {
        vector<int> v;
        if(c == '*')
            for( int i = 1 ; i < 10 ; i++ )
                v.push_back(i);
        else
            v.push_back(c-'0');
        return v;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<LL> dp(n+1,0);
        dp[0] = 1;
        for( int i = 1 ; i <= n ; i++ ) {
            if(s[i-1] == '*')
                dp[i] = 9ll * dp[i-1] % mod;
            else if(s[i-1] > '0')
                dp[i] = dp[i-1];
            if(i > 1) {
                LL mult = 0;
                vector<int> l = proc(s[i-2]);
                vector<int> r = proc(s[i-1]);
                for( int ll = 0 ; ll < l.size() ; ll++ )
                    for( int rr = 0 ; rr < r.size() ; rr++ ) {
                        int num = 10*l[ll] + r[rr];
                        if(num >= 10 && num <= 26)
                            mult++;
                    }
                dp[i] += mult * dp[i-2];
                dp[i] %= mod;
            }
        }
        return (int)dp[n];
    }
};