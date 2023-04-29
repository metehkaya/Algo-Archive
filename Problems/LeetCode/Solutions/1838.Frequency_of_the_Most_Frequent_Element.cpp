#define pb push_back
typedef long long LL;

class Solution {
public:
    int maxFrequency(vector<int>& ar, int k) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        vector<LL> sum;
        sum.pb(0);
        for( int i = 0 ; i < n ; i++ )
            sum.pb(sum[i]+ar[i]);
        int ans = 0;
        for( int i = 1 ; i <= n ; i++ ) {
            int l = 0 , r = i , last = i;
            while(l <= r) {
                int m = (l+r) >> 1;
                if(k >= (LL)(i-m)*ar[i-1]-(sum[i]-sum[m]))
                    r = m-1 , last = m;
                else
                    l = m+1;
            }
            ans = max(ans,i-last);
        }
        return ans;
    }
};