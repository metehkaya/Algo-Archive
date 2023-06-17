class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n = nums.size() , ans = INT_MAX;
        sort(nums.begin(),nums.end());
        for( int i = 1 ; i < n ; i++ )
            ans = min(ans,nums[i]-nums[i-1]);
        return ans;
    }
};
