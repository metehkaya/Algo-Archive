class Solution {
public:
    int minimumSplits(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        for( int i = n-1 ; i >= 0 ; i-- ) {
            int g = nums[i];
            dp[i] = dp[i+1]+1;
            for( int j = i+1 ; j < n ; j++ ) {
                g = __gcd(g,nums[j]);
                if(g > 1)
                    dp[i] = min(dp[i],dp[j+1]+1);
            }
        }
        return dp[0];
    }
};
