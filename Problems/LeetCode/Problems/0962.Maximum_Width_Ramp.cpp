#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    int maxWidthRamp(vector<int>& ar) {
        vector<pi> v;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            v.pb(pi(ar[i],i));
        sort(v.begin(),v.end());
        int mn = v[0].se , ans = 0;
        for( int i = 1 ; i < n ; i++ ) {
            ans = max(ans,v[i].se-mn);
            mn = min(mn,v[i].se);
        }
        return ans;
    }
};