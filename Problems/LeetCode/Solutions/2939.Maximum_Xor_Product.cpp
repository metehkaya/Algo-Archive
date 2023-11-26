typedef long long LL;

class Solution {
public:
    const long long mod = 1e9+7;
    int maximumXorProduct(LL a, LL b, int n) {
        for( int i = n-1 ; i >= 0 ; i-- ) {
            LL bmask = (1LL << i);
            int a_1 = ((a & bmask) > 0);
            int b_1 = ((b & bmask) > 0);
            if(a_1 == b_1) {
                a |= bmask;
                b |= bmask;
            }
            else {
                LL a_new = (a & (LLONG_MAX - bmask));
                LL b_new = (b & (LLONG_MAX - bmask));
                if(a_new <= b_new) {
                    a = (a_new | bmask);
                    b = b_new;
                }
                else {
                    a = a_new;
                    b = (b_new | bmask);
                }
            }
        }
        a %= mod , b %= mod;
        return a*b%mod;
    }
};

