class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n,0);
        set<int> s;
        for( int i = 0 ; i < n ; i++ ) {
            s.insert(v[i]);
            ans[i] = s.size();
        }
        s.clear();
        for( int i = n-1 ; i >= 0 ; i-- ) {
            ans[i] -= s.size();
            s.insert(v[i]);
        }
        return ans;
    }
};
