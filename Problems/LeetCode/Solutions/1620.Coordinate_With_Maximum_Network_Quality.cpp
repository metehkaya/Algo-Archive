class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& ar, int r) {
        vector<int> ans(2,0);
        int best = -1;
        int n = ar.size();
        for( int x = 0 ; x <= 50 ; x++ )
            for( int y = 0 ; y <= 50 ; y++ ) {
                int sum = 0;
                for( int i = 0 ; i < n ; i++ ) {
                    int dx = ar[i][0]-x;
                    int dy = ar[i][1]-y;
                    int d = dx*dx+dy*dy;
                    if(d <= r*r)
                        sum += ar[i][2] / (1.0 + sqrt(d));
                }
                if(sum > best) {
                    ans[0] = x;
                    ans[1] = y;
                    best = sum;
                }
            }
        return ans;
    }
};