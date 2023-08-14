typedef long long LL;

class Solution {
public:
    const int mod = (int) 1e9+7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ones;
        for( int i = 0 ; i < n ; i++ )
            if(nums[i] == 1)
                ones.push_back(i);
        if(ones.empty())
            return 0;
        LL ans = 1;
        int sz = ones.size();
        for( int i = 1 ; i < sz ; i++ )
            ans = (ans * (ones[i] - ones[i-1])) % mod;
        return ans;
    }
};
