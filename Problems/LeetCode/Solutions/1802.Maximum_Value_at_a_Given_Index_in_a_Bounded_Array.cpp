typedef long long LL;

class Solution {
public:
    LL f(LL len , LL l , LL r) {
        LL sum = 0;
        if(l <= 0) {
            int g = 1-l;
            len -= g;
            sum += g;
            l = 1;
        }
        sum += (l+r) * len / 2;
        return sum;
    }
    int maxValue(int n, int idx, int mx) {
        int ans = 0 , l = 1 , r = (int)1e9;
        while(l <= r) {
            int m = (l+r) >> 1;
            LL sum = m;
            if(idx > 0)
                sum += f(idx,m-idx,m-1);
            if(idx+1 < n)
                sum += f(n-1-idx,m-(n-1-idx),m-1);
            if(sum <= mx)
                ans = m , l = m+1;
            else
                r = m-1;
        }
        return ans;
    }
};