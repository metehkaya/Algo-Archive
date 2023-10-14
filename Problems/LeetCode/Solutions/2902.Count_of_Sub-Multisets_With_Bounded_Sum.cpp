class Solution {
public:
    const int mod = (int) 1e9+7;
    static const int maxn = 20001;
    int cnt[maxn];
    int countSubMultisets(vector<int>& nums, int l, int r) {
        vector<int> dp(r+1,0);
        for(int num : nums)
            cnt[num]++;
        dp[0] = cnt[0]+1;
        for( int i = 1 ; i <= r ; i++ )
            if(cnt[i]) {
                vector<int> dp_new(r+1,0);
                long long neg = (long long) i * cnt[i];
                for( int j = 0 ; j < i ; j++ ) {
                    int val = 0;
                    for( int k = j ; k <= r ; k += i ) {
                        val = (val + dp[k]) % mod;
                        dp_new[k] = val;
                        if(k >= neg)
                            val = (val - dp[k-neg] + mod) % mod;
                    }
                }
                dp = dp_new;
            }
        int ans = 0;
        for( int i = l ; i <= r ; i++ )
            ans = (ans + dp[i]) % mod;
        return ans;
    }
};
