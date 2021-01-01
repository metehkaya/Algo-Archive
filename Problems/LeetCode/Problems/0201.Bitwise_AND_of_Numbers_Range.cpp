class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long long x=m , y=n;
        int ans = (m&n);
        x = max(x,1LL);
        while(x < y) {
            ans &= x;
            x += (x & (-x));
        }
        return ans;
    }
};