class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size() , ans = 0;
        sort(nums.begin(), nums.end());
        for( int l = 0 , r = 1 ; l < n ; l++ ) {
            while(r < n and nums[r]-nums[l] <= 2*k)
                r++;
            ans = max(ans,r-l);
        }
        return ans;
    }
};