class Solution {
public:
    int minCostClimbingStairs(vector<int>& ar) {
        int n = ar.size();
        vector<int> dp(n+1);
        dp[0] = dp[1] = 0;
        for( int i = 2 ; i <= n ; i++ )
            dp[i] = min(dp[i-1]+ar[i-1],dp[i-2]+ar[i-2]);
        return dp[n];
    }
};