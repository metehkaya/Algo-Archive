int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long l=1,r=n,ans;
        while(l <= r) {
            long long mid = (l+r) >> 1;
            int val = guess(mid);
            if(val == 0) {
                ans = mid;
                break;
            }
            else if(val == 1)
                l = mid+1;
            else
                r = mid-1;
        }
        return (int) ans;
    }
};