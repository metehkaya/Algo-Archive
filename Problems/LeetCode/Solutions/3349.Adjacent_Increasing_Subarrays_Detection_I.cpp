class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> ok(n-k+1,true);
        for( int i = 0 ; i <= n-k ; i++ )
            for( int j = i+1 ; j < i+k ; j++ )
                if(nums[j] <= nums[j-1])
                    ok[i] = false;
        for( int i = 0 ; i <= n-2*k ; i++ )
            if(ok[i] and ok[i+k])
                return true;
        return false;
    }
};