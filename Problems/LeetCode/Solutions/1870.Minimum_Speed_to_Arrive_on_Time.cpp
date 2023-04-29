class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int l = 1 , r = 1e7 , ans = -1;
        while(l <= r) {
            int s = (l+r) >> 1;
            double total = 0;
            for( int i = 0 ; i < n ; i++ ) {
                total += (double) dist[i] / s;
                if(i < n-1)
                    total = ceil(total);
            }
            if(total <= hour) {
                ans = s;
                r = s-1;
            }
            else
                l = s+1;
        }
        return ans;
    }
};