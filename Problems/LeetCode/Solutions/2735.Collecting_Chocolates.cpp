typedef long long LL;

class Solution {
public:
    LL minCost(vector<int>& nums, int x) {
        int n = nums.size();
        LL ans = 0;
        for(int num : nums)
            ans += num;
        vector<int> min_nums = nums;
        for( int k = 1 ; k < n ; k++ ) {
            LL sum = 0;
            for( int i = 0 ; i < n ; i++ ) {
                int j = (i+k) % n;
                min_nums[i] = min(min_nums[i],nums[j]);
                sum += min_nums[i];
            }
            ans = min(ans,sum+(LL)k*x);
        }
        return ans;
    }
};
