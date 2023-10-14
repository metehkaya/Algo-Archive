class Solution {
public:
    const int mod = (int) 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> cnt(30,0);
        for(int x : nums)
            for( int i = 0 ; i < 30 ; i++ )
                if(x & (1<<i))
                    cnt[i]++;
        long long ans = 0;
        for( int i = 0 ; i < k ; i++ ) {
            long long x = 0;
            for( int j = 0 ; j < 30 ; j++ )
                if(cnt[j]) {
                    cnt[j]--;
                    x += (1<<j);
                }
            ans += x*x;
            ans %= mod;
        }
        return ans;
    }
};
