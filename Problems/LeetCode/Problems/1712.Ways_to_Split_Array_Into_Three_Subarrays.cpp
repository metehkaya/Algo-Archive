class Solution {
public:
    const int mod = (int)1e9+7;
    int waysToSplit(vector<int>& ar) {
        int n = ar.size();
        vector<int> sum(n+1);
        sum[0] = 0;
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1]+ar[i-1];
        int ans = 0;
        for( int i = 1 ; i+2 <= n ; i++ ) {
            int l = lower_bound(sum.begin(), sum.end(), 2 * sum[i]) - sum.begin();
            int r = upper_bound(sum.begin(), sum.end(), (sum[n] + sum[i]) / 2) - sum.begin();
            l = max(l,i+1);
            r = min(n,r);
            ans = (ans + max(r-l,0)) % mod;
        }
        return ans;
    }
};