class Solution {
public:
    double dp[1001][1001];
    double f(int a , int b) {
        a = max(a,0);
        b = max(b,0);
        if(a == 0 || b == 0) {
            if(a == 0 && b == 0)
                return 0.5;
            else if(a == 0)
                return 1;
            return 0;
        }
        if(dp[a][b] != -1)
            return dp[a][b];
        dp[a][b] = 0;
        for( int i = 1 ; i <= 4 ; i++ )
            dp[a][b] += f(a-i,b-4+i) / 4;
        return dp[a][b];
    }
    double soupServings(int n) {
        n = (n+24) / 25;
        if(n > 1000)
            return 1;
        for( int i = 0 ; i <= n ; i++ )
            for( int j = 0 ; j <= n ; j++ )
                dp[i][j] = -1;
        return f(n,n);
    }
};