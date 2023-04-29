class Solution {
public:
    int matrixMedian(vector<vector<int>>& v) {
        int n = v.size() , m = v[0].size();
        int thr = n*m/2 , l = 1 , r = (int) 1e6 , ans = 0;
        while(l <= r) {
            int m = (l+r) >> 1 , cnt = 0;
            for(auto& vec : v)
                cnt += upper_bound(vec.begin(),vec.end(),m) - vec.begin();
            if(cnt > thr)
                r = m-1 , ans = m;
            else
                l = m+1;
        }
        return ans;
    }
};
