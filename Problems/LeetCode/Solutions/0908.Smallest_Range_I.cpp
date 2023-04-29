class Solution {
public:
    int smallestRangeI(vector<int>& ar, int k) {
        int n = ar.size();
        int mn = ar[0] , mx = ar[0];
        for( int i = 1 ; i < n ; i++ ) {
            mn = min(mn,ar[i]);
            mx = max(mx,ar[i]);
        }
        return max(mx-mn-2*k,0);
    }
};