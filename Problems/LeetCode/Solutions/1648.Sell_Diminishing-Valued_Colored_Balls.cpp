typedef long long LL;

class Solution {
public:
    const int mod = 1000000007;
    const int maxval = 1000000000;
    int maxProfit(vector<int>& ar, int m) {
        int n = ar.size();
        int l = 0 , r = maxval , last = -1;
        while(l <= r) {
            int mid = (l+r) >> 1;
            LL cnt = 0;
            for( int i = 0 ; i < n ; i++ )
                cnt += max(ar[i]-mid,0);
            if(cnt >= m)
                last = mid , l = mid+1;
            else
                r = mid-1;
        }
        LL ans = 0;
        for( int i = 0 ; i < n ; i++ )
            if(last+1 < ar[i]) {
                int lo = last+2;
                int hi = ar[i];
                int cnt = hi-lo+1;
                m -= cnt;
                ans += (LL) (lo+hi) * cnt / 2;
            }
        ans += (LL) (last+1) * m;
        return ans % mod;
    }
};