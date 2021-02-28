typedef long long LL;

class Solution {
public:
    int divide(int dividend, int divisor) {
        LL ans = 0;
        LL x = dividend;
        LL y = divisor;
        x = abs(x);
        y = abs(y);
        for( int i = 31 ; i >= 0 ; i-- ) {
            LL val = (y<<i);
            if(x >= val) {
                x -= val;
                ans |= (1ll<<i);
            }
        }
        if((dividend>0 && divisor<0) || (dividend<0 && divisor>0))
            ans = -ans;
        return min(ans,(LL)INT_MAX);
    }
};