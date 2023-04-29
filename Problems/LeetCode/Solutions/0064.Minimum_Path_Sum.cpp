class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0)
            return 0;
        int m = grid[0].size();
        if(m == 0)
            return 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if( i > 0 || j > 0 ) {
                    int val = grid[i][j];
                    grid[i][j] = INT_MAX;
                    if(i > 0)
                        grid[i][j] = grid[i-1][j] + val;
                    if(j > 0)
                        grid[i][j] = min( grid[i][j] , grid[i][j-1] + val );
                }
        return grid[n-1][m-1];
    }
};