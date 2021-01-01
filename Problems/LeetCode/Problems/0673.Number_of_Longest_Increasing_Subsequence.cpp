class Solution {
public:
    int findNumberOfLIS(vector<int>& ar) {
        int n = ar.size();
        if(n == 0)
            return 0;
        vector<int> dp(n,1),cnt(n,1);
        int best = 0 , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < i ; j++ )
                if(ar[i] > ar[j]) {
                    if(dp[j] >= dp[i])
                        dp[i] = dp[j]+1 , cnt[i] = cnt[j];
                    else if(dp[j]+1 == dp[i])
                        cnt[i] += cnt[j];
                }
            if(dp[i] > best)
                best = dp[i] , ans = cnt[i];
            else if(dp[i] == best)
                ans += cnt[i];
        }
        return ans;
    }
};