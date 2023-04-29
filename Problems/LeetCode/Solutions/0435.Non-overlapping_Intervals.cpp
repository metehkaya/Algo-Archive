class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& ar) {
        int n = ar.size();
        if(n == 0)
            return 0;
        sort(ar.begin() , ar.end() , [](vector<int>& a , vector<int>& b) {
            return a[1] < b[1];
        });
        int x = ar[0][1] , ans = 0;
        for( int i = 1 ; i < n ; i++ )
            if(x <= ar[i][0])
                x = ar[i][1];
            else
                ans++;
        return ans;
    }
};