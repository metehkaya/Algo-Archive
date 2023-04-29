typedef long long LL;

class Solution {
public:
    const LL mod = 1e9+7;
    LL f(LL x , LL y) {
        if(y == 0)
            return 1;
        LL res = f(x,y/2);
        res = (res*res) % mod;
        if(y & 1)
            res = (res*x) % mod;
        return res;
    }
    int minNonZeroProduct(int p) {
        LL x = (1ll<<p)-2;
        LL y = x+1;
        LL z = ((1ll<<p)-1)/2;
        x %= mod , y %= mod;
        return f(x,z) % mod * y % mod;
    }
};