typedef long long LL;

class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1 , r = (int) 1e5 , ans = 0;
        while(l <= r) {
            LL m = (l+r) >> 1;
            if(m*(m+1)/2 <= n)
                ans = m , l = m+1;
            else
                r = m-1;
        }
        return ans;
    }
};