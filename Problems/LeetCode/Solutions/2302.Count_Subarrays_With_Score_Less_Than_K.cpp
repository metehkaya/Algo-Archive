typedef long long LL;

class Solution {
public:
    long long countSubarrays(vector<int>& ar, long long k) {
        vector<LL> sum;
        sum.push_back(0);
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            sum.push_back(sum[i]+ar[i]);
        LL ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int l = i+1 , r = n , last = i;
            while(l <= r) {
                int m = (l+r) >> 1;
                LL score = (sum[m]-sum[i]) * (m-i);
                if(score < k)
                    last = m , l = m+1;
                else
                    r = m-1;
            }
            ans += last-i;
        }
        return ans;
    }
};
