class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        multiset<int> s;
        long long ans = 0;
        for( int r = 0 , l = 0 ; r < n ; r++ ) {
            s.insert(nums[r]);
            while(*s.rbegin() - *s.begin() > 2) {
                s.erase(s.find(nums[l++]));
            }
            ans += r-l+1;
        }
        return ans;
    }
};
