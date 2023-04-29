class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        long long ans = 0;
        vector<int> v;
        for( int i = 0 ; i < n ; i++ ) {
            int r = upper_bound(v.begin() , v.end() , upper-nums[i]) - v.begin();
            int l = lower_bound(v.begin() , v.end() , lower-nums[i]) - v.begin();
            ans += r-l;
            v.push_back(nums[i]);
        }
        return ans;
    }
};
