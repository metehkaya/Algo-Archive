class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for( int i = 0 ; i < n-1 ; i++ ) {
            if(nums[i] == nums[i+1])
                nums[i] = 2*nums[i] , nums[i+1] = 0;
            if(nums[i])
                ans.push_back(nums[i]);
        }
        if(nums[n-1])
            ans.push_back(nums[n-1]);
        while(ans.size() < n)
            ans.push_back(0);
        return ans;
    }
};
