class Solution {
public:
    const int mod = (int) 1e9+7;
    static const int maxn = 101;
    static const int maxs = 10000;
    int dp[maxn][2*maxs+1];
    int countSubranges(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            ans = (ans + dp[i][maxs]) % mod;
            dp[i][maxs] = (dp[i][maxs] + 1) % mod;
            for( int j = 0 ; j <= 2*maxs ; j++ )
                if(dp[i][j]) {
                    dp[i+1][j+nums1[i]] = (dp[i+1][j+nums1[i]] + dp[i][j]) % mod;
                    dp[i+1][j-nums2[i]] = (dp[i+1][j-nums2[i]] + dp[i][j]) % mod;
                }
        }
        ans = (ans + dp[n][maxs]) % mod;
        return ans;
    }
};
