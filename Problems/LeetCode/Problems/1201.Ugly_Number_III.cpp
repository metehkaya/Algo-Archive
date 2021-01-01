typedef long long LL;

class Solution {
public:
    LL gcd(LL a , LL b) {
        if(!b)
            return a;
        return gcd(b,a%b);
    }
    LL lcm(LL a , LL b) {
        return a*b/gcd(a,b);
    }
    LL lcm(LL a , LL b , LL c) {
        LL l = lcm(a,b);
        return lcm(c,l);
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        LL l = 1 , r = INT_MAX , ans = -1;
        while(l <= r) {
            LL m = (l+r) >> 1;
            LL cnt = m/a + m/b + m/c - m/lcm(a,b) - m/lcm(a,c) - m/lcm(b,c) + m/lcm(a,b,c);
            if(cnt < n)
                l = m+1;
            else
                r = m-1 , ans = m;
        }
        return (int) ans;
    }
};