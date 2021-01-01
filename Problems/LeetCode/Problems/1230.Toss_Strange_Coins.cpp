class Solution {
public:
    double probabilityOfHeads(vector<double>& ar, int target) {
        int n = ar.size();
        vector<vector<double>> dp( n+1 , vector<double>( n+1 , 0.0 ) );
        dp[0][0] = 1;
        for( int i = 1 ; i <= n ; i++ ) {
            double p = ar[i-1];
            for( int j = 0 ; j <= i ; j++ ) {
                if(j < i)
                    dp[i][j] += dp[i-1][j] * (1-p);
                if(j > 0)
                    dp[i][j] += dp[i-1][j-1] * p;
            }
        }
        return dp[n][target];
    }
};