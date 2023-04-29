class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        int mx = min(n,m);
        int sumrow[n][m+1];
        int sumcol[m][n+1];
        for( int i = 0 ; i < n ; i++ ) {
            sumrow[i][0] = 0;
            for( int j = 0 ; j < m ; j++ )
                sumrow[i][j+1] = sumrow[i][j] + ar[i][j];
        }
        for( int j = 0 ; j < m ; j++ ) {
            sumcol[j][0] = 0;
            for( int i = 0 ; i < n ; i++ )
                sumcol[j][i+1] = sumcol[j][i] + ar[i][j];
        }
        for( int t = mx ; t > 1 ; t-- ) {
            for( int r = 0 ; r <= n-t ; r++ )
                for( int c = 0 ; c <= m-t ; c++ ) {
                    bool ok = true;
                    int sum = sumrow[r][c+t] - sumrow[r][c];
                    for( int i = r+1 ; i < r+t ; i++ )
                        if(sumrow[i][c+t] - sumrow[i][c] != sum)
                            ok = false;
                    if(!ok)
                        continue;
                    for( int j = c ; j < c+t ; j++ )
                        if(sumcol[j][r+t] - sumcol[j][r] != sum)
                            ok = false;
                    if(!ok)
                        continue;
                    int total = 0;
                    for( int i = 0 ; i < t ; i++ )
                        total += ar[r+i][c+i];
                    if(total != sum)
                        continue;
                    total = 0;
                    for( int i = 0 ; i < t ; i++ )
                        total += ar[r+i][c+(t-1)-i];
                    if(total != sum)
                        continue;
                    return t;
                }
        }
        return 1;
    }
};