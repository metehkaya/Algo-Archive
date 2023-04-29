typedef long long LL;

class Solution {
public:
    LL f(LL a , LL b , LL n) {
        LL total = 1;
        a *= 10 , b *= 10;
        while(a <= n) {
            total += min(n+1,b) - a;
            a *= 10 , b *= 10;
        }
        return total;
    }
    int findKthNumber(int n, int k) {
        int ans = 1;
        while(k > 1) {
            LL rem = f(ans,ans+1,n);
            if(rem < k)
                k -= rem , ans++;
            else
                k-- , ans *= 10;
        }
        return ans;
    }
};
