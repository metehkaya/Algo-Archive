typedef long long LL;
const LL mod = 1e9+7;

class Solution {
public:
    LL pw(int a , int b) {
        if(b == 0)
            return 1;
        LL res = pw(a,b/2);
        res = (res*res) % mod;
        if(b&1)
            res = (res*a) % mod;
        return res;
    }
    int monkeyMove(int n) {
        int ans = pw(2,n);
        ans = (ans-2+mod) % mod;
        return ans;
    }
};
