class Solution {
public:
    const long long inf = -1e18;
    vector<int> nums;
    vector<vector<vector<long long>>> dp;
    long long f(int id, int k, bool mark) {
        if(k == 0)
            return 0;
        if(id >= nums.size())
            return inf;
        if(dp[id][k][mark] != inf)
            return dp[id][k][mark];
        long long mult = k % 2 ? 1 : -1;
        long long val1 = f(id+1, k, true) + mult*nums[id]*k;
        long long val2 = f(id+1, k-1, false) + mult*nums[id]*k;
        dp[id][k][mark] = max(val1,val2);
        if(!mark)
            dp[id][k][mark] = max(dp[id][k][mark],f(id+1,k,false));
        return dp[id][k][mark];
    }
    long long maximumStrength(vector<int>& nums, int k) {
        this->nums = nums;
        dp.resize(nums.size(), vector<vector<long long>>(k+1, vector<long long>(2, inf)));
        return f(0,k,false);
    }
};
