class Solution {
public:
    int n,ans=1;
    const int mod = 1337;
    int f(int x , int y) {
        if(y == 0)
            return 1;
        int res = f(x,y/2);
        res = (res*res) % mod;
        if(y & 1)
            res = (res*x) % mod;
        return res;
    }
    int superPow(int a, vector<int>& b) {
        a %= mod;
        n = b.size();
        int base_a = a;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            ans = (ans * f(base_a,b[i])) % mod;
            base_a = f(base_a,10);
        }
        return ans;
    }
};