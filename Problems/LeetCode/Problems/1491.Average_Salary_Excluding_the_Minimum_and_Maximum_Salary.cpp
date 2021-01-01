class Solution {
public:
    double average(vector<int>& ar) {
        int n = ar.size();
        int total = 0;
        int mn = INT_MAX , mx = INT_MIN;
        for( int i = 0 ; i < n ; i++ ) {
            total += ar[i];
            mn = min(mn,ar[i]);
            mx = max(mx,ar[i]);
        }
        total -= mn + mx;
        return (double) total / (n-2);
    }
};