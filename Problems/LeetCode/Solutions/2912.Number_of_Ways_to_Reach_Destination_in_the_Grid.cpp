typedef long long LL;

class Solution {
public:
    const int mod = 1e9+7;
    LL calc_pow(LL x , int y) {
        if(y == 0)
            return 1;
        LL res = calc_pow(x,y/2);
        res = res * res % mod;
        if(y & 1)
            res = res * x % mod;
        return res;
    }
    void f(int n , int k , vector<vector<LL>>& dp) {
        dp[0][0] = 1 , dp[0][1] = 0;
        for( int i = 1 ; i <= k ; i++ ) {
            dp[i][0] = (n-1) * dp[i-1][1] % mod;
            dp[i][1] = (dp[i-1][0] + (n-2) * dp[i-1][1]) % mod;
        }
    }
    int numberOfWays(int n, int m, int k, vector<int>& source, vector<int>& dest) {
        vector<LL> fact(k+1) , inv_fact(k+1);
        fact[0] = inv_fact[0] = 1;
        for( int i = 1 ; i <= k ; i++ ) {
            fact[i] = fact[i-1] * i % mod;
            inv_fact[i] = calc_pow(fact[i],mod-2);
        }
        vector<vector<LL>> dpx(k+1,vector<LL>(2,0));
        vector<vector<LL>> dpy(k+1,vector<LL>(2,0));
        f(n,k,dpx);
        f(m,k,dpy);
        LL ans = 0;
        int dx = (source[0] != dest[0]);
        int dy = (source[1] != dest[1]);
        for( int kx = 0 ; kx <= k ; kx++ ) {
            int ky = k-kx;
            LL comb = fact[k] * inv_fact[kx] % mod * inv_fact[ky] % mod;
            LL add = dpx[kx][dx] * dpy[ky][dy] % mod * comb % mod;
            ans = (ans + add) % mod;
        }
        return ans;
    }
};
