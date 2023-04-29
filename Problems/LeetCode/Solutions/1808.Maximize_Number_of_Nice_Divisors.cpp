typedef long long LL;

class Solution {
public:
    const LL mod = (LL) 1e9+7;
    LL calc(int x , int y) {
        if(y == 0)
            return 1;
        LL val = calc(x,y/2);
        val = (val*val) % mod;
        if(y & 1)
            val = (val*x) % mod;
        return val;
    }
    int maxNiceDivisors(int p) {
        if(p <= 3)
            return p;
        int ans;
        if(p % 3 == 0)
            ans = calc(3,p/3);
        else if(p % 3 == 2)
            ans = (2ll * calc(3,p/3)) % mod;
        else
            ans = (4ll * calc(3,p/3-1)) % mod;
        return ans;
    }
};