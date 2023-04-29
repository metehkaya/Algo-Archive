class Solution {
public:
    vector<int> ones[200];
    int countCornerRectangles(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        int ans = 0;
        for( int r1 = 0 ; r1 < n ; r1++ )
            for( int r2 = r1+1 ; r2 < n ; r2++ ) {
                int cnt = 0;
                for( int c = 0 ; c < m ; c++ )
                    if(ar[r1][c] && ar[r2][c])
                        cnt++;
                ans += cnt*(cnt-1)/2;
            }
        return ans;
    }
};