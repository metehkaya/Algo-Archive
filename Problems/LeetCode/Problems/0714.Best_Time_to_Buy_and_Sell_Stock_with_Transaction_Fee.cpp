class Solution {
public:
    int maxProfit(vector<int>& ar, int fee) {
        int n = ar.size();
        int dp[n][2];
        for( int i = 0 ; i < n ; i++ )
            dp[i][0] = dp[i][1] = INT_MIN;
        dp[0][0] = 0;
        dp[0][1] = -(ar[0]+fee);
        for( int i = 1 ; i < n ; i++ ) {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+ar[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-(ar[i]+fee));
        }
        return dp[n-1][0];
    }
};