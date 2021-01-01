class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& ar) {
        int n = ar.size();
        if(n == 0)
            return 0;
        sort(ar.begin() , ar.end() , [](vector<int>& a , vector<int>& b) {
            return a[1] < b[1];
        });
        int ans = 1 , last = ar[0][1];
        for( int i = 1 ; i < n ; i++ ) {
            if(ar[i][0] > last)
                ans++ , last = ar[i][1];
        }
        return ans;
    }
};