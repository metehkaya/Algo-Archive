#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int validSubarrays(vector<int>& ar) {
        vector<pi> v;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            v.push_back(pi(ar[i],i));
        sort(v.begin(),v.end());
        int ans = 0;
        set<int> s;
        set<int>::iterator it;
        for( int i = 0 ; i < n ; i++ ) {
            it = s.upper_bound(v[i].se);
            int idx = n;
            if(it != s.end())
                idx = (*it);
            ans += idx-v[i].se;
            s.insert(v[i].se);
        }
        return ans;
    }
};