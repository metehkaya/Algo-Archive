class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<long long>> dp;
    long long f(int node, bool even, int k) {
        if(node == n)
            return even ? 0 : LLONG_MIN;
        if(dp[node][even] != -1)
            return dp[node][even];
        long long val1 = nums[node] + f(node+1, even, k);
        long long val2 = (nums[node] ^ k) + f(node+1, !even, k);
        return dp[node][even] = max(val1, val2);
    }
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        n = nums.size();
        this->nums = nums;
        dp.resize(n, vector<long long>(2, -1));
        return f(0, true, k);
    }
};
