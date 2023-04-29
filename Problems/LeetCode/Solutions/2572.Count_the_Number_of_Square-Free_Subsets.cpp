class Solution {
public:
    const int mod = (int) 1e9+7;
    int squareFreeSubsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> primes({2,3,5,7,11,13,17,19,23,29});
        int p = primes.size();
        int P = (1<<p);
        vector<int> val(n,0);
        for( int i = 0 ; i < n ; i++ ) {
            int num = nums[i];
            for( int j = 0 ; j < p ; j++ ) {
                int pr = primes[j];
                int pr2 = pr*pr;
                if(num % pr2 == 0) {
                    val[i] = -1;
                    break;
                }
                else if(num % pr == 0)
                    val[i] |= (1<<j);
            }
        }
        int dp[n][P];
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        if(val[0] != -1)
            dp[0][val[0]]++;
        for( int i = 1 ; i < n ; i++ )
            for( int j = 0 ; j < P ; j++ ) {
                dp[i][j] = dp[i-1][j];
                if(val[i] != -1 and (j & val[i]) == val[i])
                    dp[i][j] = (dp[i][j] + dp[i-1][j-val[i]]) % mod;
            }
        int ans = 0;
        for( int i = 0 ; i < P ; i++ )
            ans = (ans+dp[n-1][i]) % mod;
        ans = (ans - 1 + mod) % mod;
        return ans;
    }
};
