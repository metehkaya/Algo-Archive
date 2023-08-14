class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int t) {
        int n = nums.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            if(nums[i] % 2 == 0 and nums[i] <= t) {
                int j = i+1;
                while(j < n and nums[j-1] % 2 != nums[j] % 2 and nums[j] <= t)
                    j++;
                ans = max(ans,j-i);
            }
        return ans;
    }
};
