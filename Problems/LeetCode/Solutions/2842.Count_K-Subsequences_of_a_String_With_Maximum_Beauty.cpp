typedef long long LL;

class Solution {
public:
    const LL mod = (LL) 1e9+7;
    LL calc_pow(LL x , int y) {
        if(y == 0)
            return 1;
        LL res = calc_pow(x,y/2);
        res = res*res % mod;
        if(y & 1)
            res = res*x % mod;
        return res;
    }
    LL calc_comb(int x , int y) {
        long long fact[27];
        fact[0] = 1;
        for( int i = 1 ; i <= 26 ; i++ )
            fact[i] = fact[i-1]*i % mod;
        LL p = fact[x];
        LL q = fact[y] * fact[x-y] % mod;
        LL q_inv = calc_pow(q,mod-2);
        return p*q_inv % mod;
    }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        int n = s.length();
        vector<int> cnt(26,0);
        for(char c : s)
            cnt[c-'a']++;
        vector<int> freq(n+1,0);
        int total = 0;
        for(int c : cnt)
            if(c)
                total++, freq[c]++;
        if(k > total)
            return 0;
        long long ans = 1;
        for( int c = n ; c > 0 ; c-- ) {
            int f = freq[c];
            if(f == 0)
                continue;
            if(f <= k) {
                k -= f;
                ans = ans*calc_pow(c,f) % mod;
            }
            else {
                long long mult = calc_pow(c,k) * calc_comb(f,k) % mod;
                ans = ans * mult % mod;
                break;
            }
        }
        return ans;
    }
};
