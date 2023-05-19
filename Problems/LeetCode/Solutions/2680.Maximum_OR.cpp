typedef long long LL;

class Solution {
public:
    long long maximumOr(vector<int>& v, int k) {
        int n = v.size();
        vector<int> l(n),r(n);
        l[0] = v[0];
        for( int i = 1 ; i < n ; i++ )
            l[i] = (l[i-1] | v[i]);
        r[n-1] = v[n-1];
        for( int i = n-2 ; i >= 0 ; i-- )
            r[i] = (r[i+1] | v[i]);
        LL ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            LL res = 0;
            res = ((1LL * v[i]) << k);
            if(i)
                res = (res | l[i-1]);
            if(i+1 < n)
                res = (res | r[i+1]);
            ans = max(ans,res);
        }
        return ans;
    }
};
