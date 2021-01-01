class Solution {
public:
    int minCostII(vector<vector<int>>& ar) {
        int n = ar.size();
        if(n == 0)
            return 0;
        int k = ar[0].size();
        int dp[n][k];
        for( int i = 0 ; i < k ; i++ )
            dp[0][i] = ar[0][i];
        for( int i = 1 ; i < n ; i++ ) {
            int best1 = 0 , best2 = -1;
            for( int j = 1 ; j < k ; j++ ) {
                if(dp[i-1][j] <= dp[i-1][best1]) {
                    best2 = best1;
                    best1 = j;
                }
                else if(best2 == -1 || dp[i-1][j] <= dp[i-1][best2])
                    best2 = j;
            }
            for( int j = 0 ; j < k ; j++ ) {
                if(best1 != j)
                    dp[i][j] = dp[i-1][best1] + ar[i][j];
                else
                    dp[i][j] = dp[i-1][best2] + ar[i][j];
            }
        }
        int best = 0;
        for( int i = 1 ; i < k ; i++ )
            if(dp[n-1][i] < dp[n-1][best])
                best = i;
        return dp[n-1][best];
    }
};