class Solution {
public:
    int mySqrt(int x) {
        int l = 0 , r = 46340 , last = -1;
        while(l <= r) {
            int m = (l+r) >> 1;
            if(m*m <= x)
                last = m , l = m+1;
            else
                r = m-1;
        }
        return last;
    }
};