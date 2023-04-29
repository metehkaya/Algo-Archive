typedef long long LL;

class Solution {
public:
    int gcd(int a , int b) {
        if(!b)
            return a;
        return gcd(b,a%b);
    }
    const LL BIG = 1e18;
    const int mod = 1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        int c = a*b/gcd(a,b);
        LL l = 1 , r = BIG , ans = -1;
        while(l <= r) {
            LL m = (l+r) >> 1;
            LL cnt = m/a + m/b - m/c;
            if(cnt >= n) {
                ans = m;
                r = m-1;
            }
            else
                l = m+1;
        }
        return ans%mod;
    }
};