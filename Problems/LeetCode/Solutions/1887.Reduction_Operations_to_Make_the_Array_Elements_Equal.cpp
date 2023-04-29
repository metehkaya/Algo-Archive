class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ar(n);
        ar[0] = 0;
        for( int i = 1 ; i < n ; i++ )
            ar[i] = (nums[i] == nums[i-1]) ? ar[i-1] : ar[i-1]+1;
        int ans = 0;
        for( int i = 1 ; i < n ; i++ )
            ans += ar[i];
        return ans;
    }
};