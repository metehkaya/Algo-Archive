typedef long long LL;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        LL l = 1 , r = (1LL << 50) , ans;
        while(l <= r) {
            LL m = (l+r)/2 , cnt = 0;
            for( int i = 0 ; cnt < totalTrips && i < time.size() ; i++ )
                cnt += m/time[i];
            if(cnt >= (LL)totalTrips)
                ans = m , r = m-1;
            else
                l = m+1;
        }
        return ans;
    }
};
