class Solution {
public:
    int minHeightShelves(vector<vector<int>>& ar, int width) {
        int n = ar.size();
        vector<int>dp(n,INT_MAX);
        dp[0] = ar[0][1];
        for( int i = 1 ; i < n ; i++ ) {
            int w=0,h=0;
            for( int j = i ; j >= 0 && w+ar[j][0] <= width ; j-- ) {
                w += ar[j][0];
                h = max(h, ar[j][1]);
                int prevDP = (j==0) ? 0 : dp[j-1];
                dp[i] = min(dp[i], prevDP+h);
            }
        }
        return dp[n-1];
    }
};