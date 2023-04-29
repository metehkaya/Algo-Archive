typedef long long LL;
typedef pair<int,int> pi;

class Solution {
public:
    const int mod = (int) 1e9+7;
    int maxSumMinProduct(vector<int>& ar) {
        int n = ar.size();
        vector<LL> sum;
        sum.push_back(0);
        for( int i = 0 ; i < n ; i++ )
            sum.push_back(sum[i]+ar[i]);
        vector<pi> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back(pi(ar[i],i));
        sort(v.begin(),v.end());
        set<int> mys;
        mys.insert(-1);
        mys.insert(n);
        LL ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int val = v[i].first;
            int id = v[i].second;
            set<int>::iterator iter1 = mys.lower_bound(id);
            iter1--;
            set<int>::iterator iter2 = mys.upper_bound(id);
            int l = (*iter1);
            int r = (*iter2);
            ans = max(ans,val*(sum[r]-sum[l+1]));
            mys.insert(id);
        }
        return ans%mod;
    }
};