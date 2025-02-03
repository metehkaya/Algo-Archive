class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size() , ans = 1 , l = 0;
        while(l < n) {
            int r = l+1;
            while(r < n and nums[r-1] < nums[r])
                r++;
            ans = max(ans,r-l);
            l = r;
        }
        l = 0;
        while(l < n) {
            int r = l+1;
            while(r < n and nums[r-1] > nums[r])
                r++;
            ans = max(ans,r-l);
            l = r;
        }
        return ans;
    }
};