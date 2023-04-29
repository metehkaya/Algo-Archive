typedef long long LL;

class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    int kConcatenationMaxSum(vector<int>& ar, int k) {
        int n = ar.size();
        LL ans = 0;
        int total = 0;
        for( int i = 0 , sum = 0 ; i < n ; i++ ) {
            sum += ar[i];
            total += ar[i];
            sum = max(sum , 0);
            ans = max(ans , (LL)sum);
        }
        int lsum = 0 , lmin = 0;
        vector<int> lmax(n+1,0);
        for( int i = 0 ; i < n ; i++ ) {
            lsum += ar[i];
            lmin = min(lmin , lsum);
            lmax[i+1] = max(lmax[i] , lsum);
        }
        int rsum = 0 , rmin = 0;
        vector<int> rmax(n+1,0);
        for( int i = n-1 ; i >= 0 ; i-- ) {
            rsum += ar[i];
            rmin = min(rmin , rsum);
            rmax[n-i] = max(rmax[n-i-1] , rsum);
        }
        if(k > 1) {
            ans = max(ans , (LL) total*k - lmin - rmin);
            for( int i = 1 ; i < n ; i++ )
                ans = max(ans , (LL)lmax[i] + rmax[n-i]);
        }
        return ans % MOD;
    }
};