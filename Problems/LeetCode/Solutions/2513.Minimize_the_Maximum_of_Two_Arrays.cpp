typedef long long LL;

class Solution {
public:
    int minimizeSet(int a, int b, int n1, int n2) {
        LL l = 0 , r = INT_MAX , ans = LLONG_MAX;
        LL g = __gcd(a,b);
        LL lcm = (LL) a * b / g;
        while(l <= r) {
            LL n = (l+r) >> 1;
            LL cnt1 = n/b - n/lcm;
            LL cnt2 = n/a - n/lcm;
            LL rem = n-(n/a+n/b-n/lcm);
            rem -= max(n1-cnt1,0LL) + max(n2-cnt2,0LL);
            if(rem >= 0)
                ans = n , r = n-1;
            else
                l = n+1;
        }
        return ans;
    }
};
