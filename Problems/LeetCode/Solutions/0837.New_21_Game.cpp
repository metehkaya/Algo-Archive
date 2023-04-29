class Solution {
public:
    double dp[10001];
    double sum[10001];
    double new21Game(int n, int k, int maxPts) {
        if(k == 0)
            return 1;
        dp[0] = 1;
        sum[0] = 1;
        for( int i = 1 ; i <= n ; i++ ) {
            int l = max(i-maxPts,0);
            int r = min(i-1,k-1);
            if(l <= r)
                dp[i] = sum[r] - ((l == 0) ? 0 : sum[l-1]);
            dp[i] /= maxPts;
            sum[i] = sum[i-1] + dp[i];
        }
        return sum[n] - sum[k-1];
    }
};