class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(3,0));
        for( int i = 0 ; i < n ; i++ ) {
            dp[i+1] = dp[i];
            dp[i+1][nums[i]-1]++;
        }
        int ans = n;
        for( int i = 0 ; i <= n ; i++ )
            for( int j = i ; j <= n ; j++ ) {
                int v1 = i - (dp[i][0] - dp[0][0]);
                int v2 = (j-i) - (dp[j][1] - dp[i][1]);
                int v3 = (n-j) - (dp[n][2] - dp[j][2]);
                ans = min(ans,v1+v2+v3);
            }
        return ans;
    }
};
