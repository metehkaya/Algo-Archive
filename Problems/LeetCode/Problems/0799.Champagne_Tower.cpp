class Solution {
public:
    double champagneTower(int x, int r, int c) {
        double ar[r+2][r+2];
        memset(ar,0,sizeof(ar));
        ar[0][0] = x;
        for( int i = 0 ; i <= r ; i++ )
            for( int j = 0 ; j <= i ; j++ )
                if(ar[i][j] >= 1) {
                    double add = (ar[i][j]-1) / 2.0;
                    ar[i][j] -= 2*add;
                    ar[i+1][j] += add;
                    ar[i+1][j+1] += add;
                }
        return ar[r][c];
    }
};