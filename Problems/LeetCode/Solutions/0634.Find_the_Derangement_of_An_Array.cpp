typedef long long LL;

class Solution {
public:
    static const int MAXN = 1000001;
    static const int MOD = 1000000007LL;
    LL fact[MAXN];
    LL getPow(LL x , int y) {
        if(y == 0)
            return 1;
        LL res = getPow(x,y/2);
        res = (res*res) % MOD;
        if(y & 1)
            res = (res*x) % MOD;
        return res;
    }
    LL getInv(LL x) {
        return getPow(x,MOD-2);
    }
    int findDerangement(int n) {
        fact[0] = 1;
        for( int i = 1 ; i <= n ; i++ )
            fact[i] = (fact[i-1]*i) % MOD;
        LL ans = 0;
        for( int i = 0 ; i <= n ; i++ ) {
            LL p = fact[n];
            LL q = (fact[i]*fact[n-i]) % MOD;
            LL comb = (p*getInv(q)) % MOD;
            LL val = (comb*fact[n-i]) % MOD;
            if(i%2 == 0)
                ans = (ans+val) % MOD;
            else
                ans = (ans-val+MOD) % MOD;
        }
        return ans;
    }
};