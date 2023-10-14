class Solution {
public:
    const int big = (1<<20)-1;
    int maxSubarrays(vector<int>& nums) {
        int all = big;
        for(int x : nums)
            all = (all & x);
        if(all)
            return 1;
        all = big;
        int ans = 0;
        for(int x : nums) {
            all = (all & x);
            if(all == 0) {
                ans++;
                all = big;
            }
        }
        return ans;
    }
};
