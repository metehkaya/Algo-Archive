typedef long long LL;

class Solution {
public:
    int stoneGameVIII(vector<int>& ar) {
        int n = ar.size();
        vector<LL> sum(n+1,0);
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1] + ar[i-1];
        LL dpval = 0;
        LL best = sum[n]-dpval;
        for( int i = n-1 ; i >= 1 ; i-- ) {
            dpval = best;
            best = max(best,sum[i]-dpval);
        }
        return dpval;
    }
};