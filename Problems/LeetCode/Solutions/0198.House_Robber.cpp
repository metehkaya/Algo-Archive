class Solution {
public:
    int rob(vector<int>& ar) {
        int n = ar.size();
        if(n == 0)
            return 0;
        vector<int> dp[2];
        dp[0].push_back(0);
        dp[1].push_back(ar[0]);
        for( int i = 1 ; i < n ; i++ ) {
            dp[1].push_back(dp[0][i-1]+ar[i]);
            dp[0].push_back(max(dp[0][i-1],dp[1][i-1]));
        }
        return max(dp[0][n-1],dp[1][n-1]);
    }
};