class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> d(n,vector<int>(n,n-1));
        x-- , y--;
        d[x][y] = d[y][x] = 1;
        for( int i = 0 ; i < n ; i++ )
            d[i][i] = 0;
        for( int i = 1 ; i < n ; i++ )
            d[i-1][i] = d[i][i-1] = 1;
        for( int k = 0 ; k < n ; k++ )
            for( int i = 0 ; i < n ; i++ )
                for( int j = 0 ; j < n ; j++ )
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
        vector<int> ans(n,0);
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                ans[d[i][j]-1] += 2;
        return ans;
    }
};
