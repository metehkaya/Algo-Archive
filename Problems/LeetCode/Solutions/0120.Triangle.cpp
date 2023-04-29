class Solution {
public:
    int minimumTotal(vector<vector<int>>& ar) {
        int n = ar.size();
        vector<int> dp(n,INT_MAX);
        dp[0] = ar[0][0];
        for( int i = 1 ; i < n ; i++ ) {
            vector<int> dp_new(n,INT_MAX);
            for( int j = 0 ; j <= i ; j++ ) {
                if(j == 0)
                    dp_new[j] = dp[j];
                else if(j == i)
                    dp_new[j] = dp[j-1];
                else
                    dp_new[j] = min(dp[j-1],dp[j]);
                dp_new[j] += ar[i][j];
            }
            dp = dp_new;
        }
        int ans = INT_MAX;
        for( int i = 0 ; i < n ; i++ )
            ans = min(ans,dp[i]);
        return ans;
    }
};