typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    static bool comp(vi& a, vi& b) {
        if(a[0] != b[0])
            return a[0] < b[0];
        return a[1] > b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& ar) {
        sort(ar.begin(), ar.end(), comp);
        int cnt = 0;
        int mx = INT_MIN;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            if( ar[i][1] <= mx )
                cnt++;
            else
                mx = ar[i][1];
        }
        return n-cnt;
    }
};