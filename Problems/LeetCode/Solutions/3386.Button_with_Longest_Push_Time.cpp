class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int n = events.size() , last = 0 , maxd = -1 , ans = -1;
        for( int i = 0 ; i < n ; i++ ) {
            int idx = events[i][0] , t = events[i][1];
            int d = t - last;
            last = t;
            if(d > maxd or (d == maxd and idx < ans))
                ans = idx , maxd = d;
        }
        return ans;
    }
};