#define mod 1000000007

class Solution {
public:
    int add[1001];
    int del[1001];
    int peopleAwareOfSecret(int n, int delay, int forget) {
        if(delay+1 <= n)
            add[delay+1]++;
        if(forget+1 <= n)
            del[forget+1]++;
        int ans = 0;
        int curr = 0;
        if(forget >= n)
            ans = 1;
        for( int i = 1 ; i <= n ; i++ ) {
            curr = (curr + add[i]) % mod;
            curr = (curr - del[i] + mod) % mod;
            if(i+delay <= n)
                add[i+delay] = (add[i+delay] + curr) % mod;
            if(i+forget <= n)
                del[i+forget] = (del[i+forget] + curr) % mod;
            if(i+forget > n)
                ans = (ans + curr) % mod;
        }
        return ans;
    }
};
