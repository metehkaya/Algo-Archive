typedef long long LL;

class NumMatrix {
public:
    LL dp[201][201];
    NumMatrix(vector<vector<int>>& ar) {
        memset(dp,0,sizeof(dp));
        int n = ar.size();
        int m = ar[0].size();
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ )
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + ar[i-1][j-1];
    }
    int sumRegion(int r1, int c1, int r2, int c2) {
        r2++,c2++;
        return dp[r2][c2] + dp[r1][c1] - dp[r2][c1] - dp[r1][c2];
    }
};