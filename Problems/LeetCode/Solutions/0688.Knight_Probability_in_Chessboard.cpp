class Solution {
public:
    int dir[8][2]={{1,2},{2,1},{1,-2},{2,-1},{-1,2},{-2,1},{-1,-2},{-2,-1}};
    double knightProbability(int n, int k, int r, int c) {
        vector<vector<double>> dpNew(n, vector<double>(n));
        dpNew[r][c] = 1.0;
        for( int step = 0 ; step < k ; step++ ) {
            vector<vector<double>> dpOld = dpNew;
            for( int i = 0 ; i < n ; i++ )
                for( int j = 0 ; j < n ; j++ ) {
                    dpNew[i][j] = 0;
                    for( int k = 0 ; k < 8 ; k++ ) {
                        int x = i + dir[k][0];
                        int y = j + dir[k][1];
                        if( x >= 0 && x < n && y >= 0 && y < n )
                            dpNew[i][j] += dpOld[x][y] / 8.0;
                    }
                }
        }
        double sum = 0.0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                sum += dpNew[i][j];
        return sum;
    }
};