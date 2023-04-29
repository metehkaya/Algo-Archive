typedef long long LL;

class Solution {
public:
    const int mod = (int) 1e9+7;
    LL f(LL x , LL y) {
        if(y == 0)
            return 1;
        LL temp = f(x,y/2);
        temp = (temp*temp) % mod;
        if(y&1)
            temp = (temp*x) % mod;
        return temp;
    }
    int countGoodNumbers(LL n) {
        LL ans = 5;
        ans = (ans*f(4,n/2))%mod;
        ans = (ans*f(5,(n-1)/2))%mod;
        return ans;
    }
};