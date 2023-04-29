const int mod = (int) 1e9+7;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        for(int num : nums)
            sum += num;
        if(sum < 2*k)
            return 0;
        vector<int> dp(k,0);
        dp[0] = 1;
        for(int num : nums)
            for( int i = k-1-num ; i >= 0 ; i-- )
                dp[i+num] = (dp[i+num] + dp[i]) % mod;
        int ans = 1;
        for( int i = 0 ; i < n ; i++ )
            ans = (ans << 1) % mod;
        int total = 0;
        for( int i = 0 ; i < k ; i++ )
            total = (total + dp[i]) % mod;
        ans = (ans-total+mod) % mod;
        ans = (ans-total+mod) % mod;
        return ans;
    }
};
