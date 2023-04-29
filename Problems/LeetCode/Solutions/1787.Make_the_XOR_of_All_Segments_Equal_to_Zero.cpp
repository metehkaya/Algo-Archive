class Solution {
public:
    static const int maxb = 1024;
    static const int maxn = 2000;
    int dp[maxn][maxb];
    int cnt[maxn][maxb];
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp,0,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        for( int i = 0 ; i < n ; i++ ) {
            cnt[i%k][nums[i]]++;
            if(i%k == 0)
                dp[0][nums[i]]++;
        }
        for( int i = 1 ; i < k ; i++ ) {
            int mx = 0;
            for( int j = 0 ; j < maxb ; j++ )
                mx = max(mx,dp[i-1][j]);
            for( int j = 0 ; j < maxb ; j++ )
                dp[i][j] = mx;
            for( int val = 0 ; val < maxb ; val++ )
                if(cnt[i][val])
                    for( int j = 0 ; j < maxb ; j++ )
                        dp[i][j] = max(dp[i][j], dp[i-1][j^val]+cnt[i][val]);
        }
        return n-dp[k-1][0];
    }
};
