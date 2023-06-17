class Solution {
public:
    const int mod = (1e9+7);
    static const int maxn = 14;
    static const int maxN = (1 << maxn);
    int n,N;
    vector<int> nums;
    int dp[maxN][maxn];
    int f(int id , int bmask) {
        if(bmask == N)
            return 1;
        if(dp[bmask][id] != -1)
            return dp[bmask][id];
        dp[bmask][id] = 0;
        for( int i = 0 ; i < n ; i++ )
            if((bmask & (1<<i)) == 0 and (nums[id] % nums[i] == 0 or nums[i] % nums[id] == 0))
                dp[bmask][id] = (dp[bmask][id] + f(i,(bmask | (1<<i)))) % mod;
        return dp[bmask][id];
    }
    int specialPerm(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        N = (1<<n) - 1;
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            ans = (ans + f(i,(1<<i))) % mod;
        return ans;
    }
};
