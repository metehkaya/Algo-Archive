class Solution {
public:
    int binarySearchableNumbers(vector<int>& v) {
        int n = v.size() , ans = 0;
        vector<bool> mark(n,false);
        int mx = INT_MIN;
        for( int i = 0 ; i < n ; i++ ) {
            mark[i] = (v[i] > mx);
            mx = max(mx,v[i]);
        }
        int mn = INT_MAX;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            ans += (mark[i] and v[i] < mn);
            mn = min(mn,v[i]);
        }
        return ans;
    }
};
