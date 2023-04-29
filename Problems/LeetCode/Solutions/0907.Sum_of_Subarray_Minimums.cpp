typedef long long LL;
typedef pair<int,int> pi;

class Solution {
public:
    const int MOD = (int) 1e9+7;
    int sumSubarrayMins(vector<int>& ar) {
        int n = ar.size();
        set<int> s;
        vector<pi> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back(pi(ar[i],i));
        sort(v.begin(),v.end());
        int ans = 0;
        s.insert(-1);
        s.insert(n);
        for( int i = 0 ; i < n ; i++ ) {
            int val = v[i].first;
            int idx = v[i].second;
            auto it = s.lower_bound(idx);
            int r = (*it);
            it--;
            int l = (*it);
            LL add = (LL) (idx-l) * (r-idx) % MOD;
            add = (add * val) % MOD;
            ans = (ans + add) % MOD;
            s.insert(idx);
        }
        return ans;
    }
};