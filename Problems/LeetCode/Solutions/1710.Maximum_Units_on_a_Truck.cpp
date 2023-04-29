class Solution {
public:
    int units[1001];
    int maximumUnits(vector<vector<int>>& ar, int sz) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            units[ar[i][1]] += ar[i][0];
        int ans = 0;
        for( int i = 1000 ; i >= 1 ; i-- ) {
            int mn = min(sz,units[i]);
            sz -= mn;
            ans += i*mn;
        }
        return ans;
    }
};