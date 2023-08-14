class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , ans = 1;
        vector<vector<int>> dp(2,vector<int>(n,0));
        vector<int> nums[2];
        nums[0] = nums1;
        nums[1] = nums2;
        dp[0][0] = dp[1][0] = 1;
        for( int i = 1 ; i < n ; i++ )
            for( int j = 0 ; j < 2 ; j++ ) {
                dp[j][i] = 1;
                if(nums[j][i] >= nums[0][i-1])
                    dp[j][i] = max(dp[j][i],dp[0][i-1]+1);
                if(nums[j][i] >= nums[1][i-1])
                    dp[j][i] = max(dp[j][i],dp[1][i-1]+1);
                ans = max(ans,dp[j][i]);
            }
        return ans;
    }
};
