#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        int n = d.size();
        int m = w.size();
        vector<pi> v;
        for( int i = 0 ; i < n ; i++ )
            v.pb(pi(d[i],p[i]));
        sort(v.begin(),v.end());
        sort(w.begin(),w.end());
        int best = -1 , ans = 0;
        for( int i = 0 , j = 0 ; i < m ; i++ ) {
            while(j < n && v[j].fi <= w[i])
                best = max(best,v[j++].se);
            if(best != -1)
                ans += best;
        }
        return ans;
    }
};