class Solution {
public:
    int dp[101][101];
    int maxSumSubmatrix(vector<vector<int>>& ar, int k) {
        int n = ar.size();
        int m = ar[0].size();
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ )
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + ar[i-1][j-1];
        int ans = INT_MIN;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ )
                for( int i2 = i ; i2 <= n ; i2++ )
                    for( int j2 = j ; j2 <= m ; j2++ ) {
                        int score = dp[i2][j2] - dp[i-1][j2] - dp[i2][j-1] + dp[i-1][j-1];
                        if(score <= k)
                            ans = max(ans,score);
                    }
        return ans;
    }
};