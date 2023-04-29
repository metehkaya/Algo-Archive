class Solution {
public:
    int countLatticePoints(vector<vector<int>>& ar) {
        int ans = 0;
        int n = ar.size();
        for( int x = 0 ; x <= 200 ; x++ )
            for( int y = 0 ; y <= 200 ; y++ )
                for( int i = 0 ; i < n ; i++ ) {
                    int dx = x - ar[i][0];
                    int dy = y - ar[i][1];
                    int r = ar[i][2];
                    if(dx*dx + dy*dy <= r*r) {
                        ans++;
                        break;
                    }
                }
        return ans;
    }
};
