typedef long long LL;

class Solution {
public:
    const LL mod = (int) 1e9+7;
    LL calc_pow(LL x , int y) {
        if(y == 0)
            return 1;
        LL res = calc_pow(x,y/2);
        res = (res*res) % mod;
        if(y & 1)
            res = (res*x) % mod;
        return res;
    }
    int countGoodSubsequences(string s) {
        int n = s.length();
        vector<LL> fact(n+1);
        vector<LL> inv_fact(n+1);
        fact[0] = inv_fact[0] = 1;
        for( LL i = 1 ; i <= n ; i++ ) {
            fact[i] = (fact[i-1] * i) % mod;
            inv_fact[i] = calc_pow(fact[i], mod-2);
        }
        vector<int> cnt(26,0);
        for(char c : s)
            cnt[c-'a']++;
        LL ans = 0;
        for( int k = 1 ; k <= n ; k++ ) {
            LL res = 1;
            for( int i = 0 ; i < 26 ; i++ ) {
                LL mult = 0;
                if(cnt[i] >= k) {
                    LL p = fact[cnt[i]];
                    LL q = (inv_fact[k] * inv_fact[cnt[i]-k]) % mod;
                    mult = p*q % mod;
                }
                mult = (mult+1) % mod;
                res = (res*mult) % mod;
            }
            res = (res-1+mod) % mod;
            ans = (ans+res) % mod;
        }
        return (int) ans;
    }
};
