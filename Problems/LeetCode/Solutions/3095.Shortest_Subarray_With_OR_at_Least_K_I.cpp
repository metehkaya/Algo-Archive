class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int threshold) {
        int n = nums.size();
        int ans = n+1;
        for( int i = 0 ; i < n ; i++ ) {
            int val = 0;
            for( int j = i ; j < n ; j++ ) {
                val = (val | nums[j]);
                if(val >= threshold) {
                    ans = min(ans,j-i+1);
                    break;
                }
            }
        }
        return ans == n+1 ? -1 : ans;
    }
};
