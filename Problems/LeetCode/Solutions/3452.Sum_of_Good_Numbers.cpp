class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n = nums.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            bool ok = true;
            if(i-k >= 0 and nums[i] <= nums[i-k])
                ok = false;
            if(i+k < n and nums[i] <= nums[i+k])
                ok = false;
            if(ok)
                ans += nums[i];
        }
        return ans;
    }
};