#define mod 1000000007LL
typedef long long LL;
typedef vector<LL> vi;
typedef vector<vi> vii;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        LL dp[n][m][3];
        memset(dp,0,sizeof(dp));
        if(ar[n-1][m-1] > 0)
            dp[n-1][m-1][0] = ar[n-1][m-1];
        else if(ar[n-1][m-1] < 0)
            dp[n-1][m-1][1] = -ar[n-1][m-1];
        else
            dp[n-1][m-1][2] = 1;
        for( int i = n-1 ; i >= 0 ; i-- )
            for( int j = m-1 ; j >= 0 ; j-- )
                if(i < n-1 || j < m-1) {
                    if(j < m-1 && dp[i][j+1][0]) {
                        LL x = dp[i][j+1][0] * ar[i][j];
                        if(x > 0)
                            dp[i][j][0] = max(dp[i][j][0],x);
                        else if(x < 0)
                            dp[i][j][1] = max(dp[i][j][1],-x);
                        else
                            dp[i][j][2] = 1;
                    }
                    if(j < m-1 && dp[i][j+1][1]) {
                        LL x = -dp[i][j+1][1] * ar[i][j];
                        if(x > 0)
                            dp[i][j][0] = max(dp[i][j][0],x);
                        else if(x < 0)
                            dp[i][j][1] = max(dp[i][j][1],-x);
                        else
                            dp[i][j][2] = 1;
                    }
                    if(j < m-1 && dp[i][j+1][2])
                        dp[i][j][2] = 1;
                    if(i < n-1 && dp[i+1][j][0]) {
                        LL x = dp[i+1][j][0] * ar[i][j];
                        if(x > 0)
                            dp[i][j][0] = max(dp[i][j][0],x);
                        else if(x < 0)
                            dp[i][j][1] = max(dp[i][j][1],-x);
                        else
                            dp[i][j][2] = 1;
                    }
                    if(i < n-1 && dp[i+1][j][1]) {
                        LL x = -dp[i+1][j][1] * ar[i][j];
                        if(x > 0)
                            dp[i][j][0] = max(dp[i][j][0],x);
                        else if(x < 0)
                            dp[i][j][1] = max(dp[i][j][1],-x);
                        else
                            dp[i][j][2] = 1;
                    }
                    if(i < n-1 && dp[i+1][j][2])
                        dp[i][j][2] = 1;
                }
        if(dp[0][0][0])
            return dp[0][0][0] % mod;
        if(dp[0][0][2])
            return 0;
        return -1;
    }
};