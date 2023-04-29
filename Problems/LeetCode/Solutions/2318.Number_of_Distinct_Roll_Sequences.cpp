#define mod 1000000007

class Solution {
public:
    int n;
    int g[6][6];
    int dp[10001][6][6];
    int gcd(int x , int y) {
        if(!y)
            return x;
        return gcd(y,x%y);
    }
    int f(int k , int x , int y) {
        if(k == n)
            return 1;
        if(dp[k][x][y] != -1)
            return dp[k][x][y];
        dp[k][x][y] = 0;
        for( int i = 0 ; i < 6 ; i++ )
            if(g[i][y] == 1) {
                if(i == y)
                    continue;
                if(k >= 2 && i == x)
                    continue;
                dp[k][x][y] += f(k+1,y,i);
                dp[k][x][y] %= mod;
            }
        return dp[k][x][y];
    }
    int distinctSequences(int n) {
        for( int i = 0 ; i < 6 ; i++ )
            for( int j = 0 ; j < 6 ; j++ )
                g[i][j] = gcd(i+1,j+1);
        this->n = n;
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for( int i = 0 ; i < 6 ; i++ )
            ans = (ans + f(1,0,i)) % mod;
        return ans;
    }
};
