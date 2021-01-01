class Solution {
public:
    int maxSideLength(vector<vector<int>>& ar, int mx) {
        int ans = 0;
        int n = ar.size() , m = ar[0].size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1,0));
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ )
                dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + ar[i-1][j-1];
        for( int k = min(n,m) ; k >= 1 ; k-- )
            for( int i = k ; i <= n ; i++ )
                for( int j = k ; j <= m ; j++ ) {
                    int sum = dp[i][j] - dp[i][j-k] - dp[i-k][j] + dp[i-k][j-k];
                    if(sum <= mx)
                        return k;
                }
        return 0;
    }
};