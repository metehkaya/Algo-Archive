class Solution {
public:
    int sumCounts(vector<int>& v) {
        int n = v.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            set<int> s;
            for( int j = i ; j < n ; j++ ) {
                s.insert(v[j]);
                int sz = s.size();
                ans += sz*sz;
            }
        }
        return ans;
    }
};
