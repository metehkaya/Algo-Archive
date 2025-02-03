class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int s = max(0,i-nums[i]) ; s <= i ; s++ )
                ans += nums[s];
        return ans;
    }
};