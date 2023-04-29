typedef long long LL;

class Solution {
public:
    bool isPerfectSquare(int num) {
        LL l=1,r=(1LL<<16);
        while(l <= r) {
            LL mid = (l+r) >> 1;
            LL sq = mid*mid;
            if(sq == num)
                return true;
            else if(sq > num)
                r = mid-1;
            else
                l = mid+1;
        }
        return false;
    }
};