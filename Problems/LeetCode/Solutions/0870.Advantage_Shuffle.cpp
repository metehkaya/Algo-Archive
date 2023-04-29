#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    vector<int> advantageCount(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<pi> v;
        multiset<int> s;
        for( int i = 0 ; i < n ; i++ ) {
            s.insert(a[i]);
            v.pb(pi(b[i],i));
        }
        sort(v.begin(),v.end());
        vector<int> ans(n);
        for( int i = 0 ; i < n ; i++ ) {
            int val = v[i].fi;
            int idx = v[i].se;
            multiset<int>::iterator it = s.upper_bound(val);
            if(it == s.end())
                it = s.begin();
            ans[idx] = (*it);
            s.erase(it);
        }
        return ans;
    }
};