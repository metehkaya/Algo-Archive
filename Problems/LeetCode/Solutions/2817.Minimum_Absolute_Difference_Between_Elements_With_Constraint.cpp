class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size() , ans = INT_MAX;
        set<int> s;
        for( int i = 0 ; i < n ; i++ )
            if(i >= x) {
                s.insert(nums[i-x]);
                auto it = s.lower_bound(nums[i]);
                if(it != s.end())
                    ans = min(ans,abs(nums[i]-(*it)));
                if(it != s.begin()) {
                    it--;
                    ans = min(ans,abs(nums[i]-(*it)));
                }
            }
        return ans;
    }
};