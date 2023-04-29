typedef long long LL;

class Solution {
public:
    int minEatingSpeed(vector<int>& ar, int h) {
        int n = ar.size();
        int ans = -1 , l = 1 , r = 1e9;
        while(l <= r) {
            LL cnt = 0;
            int m = (l+r) >> 1;
            for( int i = 0 ; i < n ; i++ )
                cnt += ar[i]/m + ((ar[i]%m)>0);
            if(cnt <= h)
                ans = m , r = m-1;
            else
                l = m+1;
        }
        return ans;
    }
};