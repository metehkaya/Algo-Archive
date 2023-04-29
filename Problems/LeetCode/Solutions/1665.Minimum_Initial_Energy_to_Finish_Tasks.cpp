class Solution {
public:
    int minimumEffort(vector<vector<int>>& ar) {
        sort(ar.begin() , ar.end() , [&](vector<int>& a , vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        int n = ar.size();
        int l = 0 , r = 1e9 , ans = -1;
        while(l <= r) {
            int T = (l+r) >> 1;
            bool ok = true;
            for( int i = 0 , t = T ; i < n && ok ; i++ ) {
                if(t < ar[i][1])
                    ok = false;
                t -= ar[i][0];
            }
            if(ok)
                ans = T , r = T-1;
            else
                l = T+1;
        }
        return ans;
    }
};