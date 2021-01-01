class Solution {
public:
    int countNegatives(vector<vector<int>>& ar) {
        int ans = 0;
        int last = 0;
        int n = ar.size();
        int m = ar[0].size();
        for( int i = 0 ; i < n ; i++ ) {
            while(last < m && ar[i][m-last-1] < 0)
                last++;
            ans += last;
        }
        return ans;
    }
};