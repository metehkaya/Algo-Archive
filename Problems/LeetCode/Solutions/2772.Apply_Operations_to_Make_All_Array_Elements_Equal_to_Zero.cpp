class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size() , total = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(i >= k)
                total -= nums[i-k];
            if(total > nums[i])
                return false;
            if(i > n-k and total != nums[i])
                return false;
            nums[i] -= total;
            total += nums[i];
        }
        return true;
    }
};
