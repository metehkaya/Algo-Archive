class Solution {
public:
    int f(int x , int y) {
        int res = 1;
        while(y--)
            res *= x;
        return res;
    }
    int integerBreak(int n) {
        int ans = 0;
        for( int k = 2 ; k <= n ; k++ ) {
            int x = n/k;
            int y = x+1;
            int cnt_y = n%k;
            int cnt_x = k-cnt_y;
            ans = max(ans,f(x,cnt_x)*f(y,cnt_y));
        }
        return ans;
    }
};