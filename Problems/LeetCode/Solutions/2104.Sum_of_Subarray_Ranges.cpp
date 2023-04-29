class Solution {
public:
    long long subArrayRanges(vector<int>& ar) {
        int n = ar.size();
        long long ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int mn = INT_MAX , mx = INT_MIN;
            for( int j = i ; j < n ; j++ ) {
                mn = min(mn,ar[j]);
                mx = max(mx,ar[j]);
                ans += mx-mn;
            }
        }
        return ans;
    }
};
