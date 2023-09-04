class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        long long ans = 0;
        int curr = 0;
        map<int,int> dp;
        dp[0] = 1;
        for(int x : nums) {
            curr += (x % m == k);
            curr %= m;
            int prev = (curr-k+m) % m;
            ans += dp[prev];
            dp[curr]++;
        }
        return ans;
    }
};
