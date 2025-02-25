class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int score = nums[0] + nums[1] , ans = 1 , n = nums.size();
        for( int i = 3 ; i < n ; i += 2 )
            if(nums[i] + nums[i-1] == score)
                ans++;
            else
                break;
        return ans;
    }
};