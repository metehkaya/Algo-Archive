typedef long long LL;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& ar) {
        int n = ar.size();
        if(n == 0) {
            if(startFuel >= target)
                return 0;
            return -1;
        }
        LL dp[n][n+1];
        memset(dp,-1,sizeof(dp));
        if(startFuel >= ar[0][0])
            dp[0][0] = startFuel-ar[0][0];
        if(dp[0][0] >= 0)
            dp[0][1] = dp[0][0]+ar[0][1];
        for( int i = 1 ; i < n ; i++ ) {
            int diff = ar[i][0]-ar[i-1][0];
            for( int j = 0 ; j <= i ; j++ )
                if(diff <= dp[i-1][j])
                    dp[i][j] = dp[i-1][j]-diff;
            for( int j = i ; j >= 0 ; j-- )
                if(dp[i][j] >= 0)
                    dp[i][j+1] = max(dp[i][j+1],dp[i][j]+ar[i][1]);
        }
        int diff = target-ar[n-1][0];
        for( int i = 0 ; i <= n ; i++ )
            if(dp[n-1][i] >= diff)
                return i;
        return -1;
    }
};