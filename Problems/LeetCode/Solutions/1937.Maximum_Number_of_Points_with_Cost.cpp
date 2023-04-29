typedef long long LL;

class Solution {
public:
    LL maxPoints(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        vector<LL> dp(m);
        for( int i = 0 ; i < m ; i++ )
            dp[i] = ar[0][i];
        for( int i = 1 ; i < n ; i++ ) {
            vector<LL> dp_new(m);
            LL best = LLONG_MIN;
            for( int j = 0 ; j < m ; j++ ) {
                best = max(best,dp[j]+j);
                dp_new[j] = ar[i][j] + best - j;
            }
            best = LLONG_MIN;
            for( int j = m-1 ; j >= 0 ; j-- ) {
                best = max(best,dp[j]-j);
                dp_new[j] = max(dp_new[j] , ar[i][j]+best+j);
            }
            dp = dp_new;
        }
        LL ans = LLONG_MIN;
        for( int i = 0 ; i < m ; i++ )
            ans = max(ans,dp[i]);
        return ans;
    }
};