typedef long long LL;

class Solution {
public:
    int reachNumber(int t) {
        t = abs(t);
        LL l = 0 , r = 50000 , n = 0;
        while(l <= r) {
            LL mid = (l+r) >> 1;
            if(mid*(mid+1)/2 >= t)
                n = mid , r = mid-1;
            else
                l = mid+1;
        }
        LL ans;
        bool done = false;
        while(!done) {
            if(t % 2 == 0 && (n % 4 == 0 || n % 4 == 3))
                done = true;
            else if(t % 2 == 1 && (n % 4 == 1 || n % 4 == 2))
                done = true;
            ans = n++;
        }
        return ans;
    }
};