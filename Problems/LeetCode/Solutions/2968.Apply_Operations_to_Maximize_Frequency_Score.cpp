class Solution {
public:
    long long check(int l , int r , vector<int>& v , vector<long long>& sum) {
        int m = (l+r) >> 1;
        long long cost_l = (long long) v[m] * (m-l) - (sum[m] - sum[l]);
        long long cost_r = (sum[r+1] - sum[m+1]) - (long long) v[m] * (r-m);
        return cost_l + cost_r;
    }
    int maxFrequencyScore(vector<int>& v, long long k) {
        int n = v.size();
        sort(v.begin(),v.end());
        vector<long long> sum(n+1,0);
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1] + v[i-1];
        int ans = 1 , l = 1 , r = n;
        while(l <= r) {
            bool ok = false;
            int m = (l+r) >> 1;
            for( int i = 0 ; i <= n-m ; i++ )
                if(check(i,i+m-1,v,sum) <= k) {
                    ok = true;
                    break;
                }
            if(ok)
                l = m+1 , ans = m;
            else
                r = m-1;
        }
        return ans;
    }
};