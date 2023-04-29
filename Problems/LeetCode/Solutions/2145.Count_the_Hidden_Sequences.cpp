typedef long long LL;

class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        vector<LL> v;
        int n = diff.size();
        LL l = 0 , r = 0;
        v.push_back(0);
        for( int i = 0 ; i < n ; i++ ) {
            v.push_back(v[i]+diff[i]);
            l = min(l,v[i+1]);
            r = max(r,v[i+1]);
        }
        LL diff1 = r-l;
        LL diff2 = upper-lower;
        return (int) max(diff2-diff1+1,0LL);
    }
};
