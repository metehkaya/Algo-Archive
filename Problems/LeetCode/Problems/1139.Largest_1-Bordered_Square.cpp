class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        vector<vector<int>> rows(n+1,vector<int>(m+1,0));
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ )
                rows[i][j] = rows[i][j-1] + ar[i-1][j-1];
        vector<vector<int>> cols(m+1,vector<int>(n+1,0));
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ )
                cols[j][i] = cols[j][i-1] + ar[i-1][j-1];
        for( int len = min(n,m) ; len >= 1 ; len-- )
            for( int i = 0 ; i <= n-len ; i++ )
                for( int j = 0 ; j <= m-len ; j++ ) {
                    if( rows[i+1][j+len] - rows[i+1][j] < len )
                        continue;
                    if( rows[i+len][j+len] - rows[i+len][j] < len )
                        continue;
                    if( cols[j+1][i+len] - cols[j+1][i] < len )
                        continue;
                    if( cols[j+len][i+len] - cols[j+len][i] < len )
                        continue;
                    return len*len;
                }
        return 0;
    }
};