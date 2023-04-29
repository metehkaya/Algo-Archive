class Solution {
public:
    int minSideJumps(vector<int>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            ar[i]--;
        int dp[n][3];
        memset(dp,-1,sizeof(dp));
        dp[0][1] = 0;
        for( int i = 1 ; i < n ; i++ )
            for( int j = 0 ; j < 3 ; j++ ) {
                if(ar[i] != j) {
                    dp[i][j] = INT_MAX;
                    for( int k = 0 ; k < 3 ; k++ )
                        if(dp[i-1][k] != -1)
                            if(ar[i-1] != j)
                                dp[i][j] = min(dp[i][j],dp[i-1][k]+(j!=k));
                    if(dp[i][j] == INT_MAX)
                        dp[i][j] = -1;
                }
            }
        int ans = INT_MAX;
        for( int i = 0 ; i < 3 ; i++ )
            if(dp[n-1][i] != -1)
                ans = min(ans,dp[n-1][i]);
        return ans == INT_MAX ? -1 : ans;
    }
};