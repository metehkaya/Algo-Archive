typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    int getApple(int r1, int c1, int r2, int c2, vvi& sum) {
        return sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1];
    }
    int f(int r, int c, int k, int n, int m, int total, vvi& sum, vvvi& dp) {
        if(k == 0)
            return 1;
        if(dp[k][r][c] != -1)
            return dp[k][r][c];
        dp[k][r][c] = 0;
        for( int i = r+1 ; i <= n ; i++ ) {
            int slime = getApple(i,c,n,m,sum);
            if(slime != 0 && slime != total)
                dp[k][r][c] = ( dp[k][r][c] + f(i,c,k-1,n,m,slime,sum,dp) ) % MOD;
        }
        for( int i = c+1 ; i <= m ; i++ ) {
            int slime = getApple(r,i,n,m,sum);
            if(slime != 0 && slime != total)
                dp[k][r][c] = ( dp[k][r][c] + f(r,i,k-1,n,m,slime,sum,dp) ) % MOD;
        }
        return dp[k][r][c];
    }
    int ways(vector<string>& ar, int k) {
        int n = ar.size();
        int m = ar[0].size();
        vvi sum(n+1, vi(m+1,0));
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ ) {
                int add = ar[i-1][j-1] == 'A';
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + add;
            }
        vvvi dp(k, vvi(n+1, vi(m+1, -1)));
        return f(1,1,k-1,n,m,sum[n][m],sum,dp);
    }
};