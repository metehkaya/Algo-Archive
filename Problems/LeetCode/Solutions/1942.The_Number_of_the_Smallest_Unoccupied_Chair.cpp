#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;
typedef pair<int,pi> pii;

class Solution {
public:
    int n;
    vector<pii> ar;
    set<int> myset;
    int smallestChair(vector<vector<int>>& times, int f) {
        n = times.size();
        for( int i = 0 ; i < n ; i++ ) {
            int s = times[i][0];
            int e = times[i][1];
            ar.pb(pii(s,pi(1,i)));
            ar.pb(pii(e,pi(0,i)));
        }
        sort(ar.begin(),ar.end());
        vector<int> ans(n,-1);
        for( int i = 0 ; i < n ; i++ )
            myset.insert(i);
        for( int i = 0 ; i < 2*n ; i++ ) {
            pii p = ar[i];
            int t = p.fi;
            int idx = p.se.se;
            int type = p.se.fi;
            if(type == 0)
                myset.insert(ans[idx]);
            else {
                set<int>::iterator it = myset.begin();
                ans[idx] = (*it);
                myset.erase(it);
            }
        }
        return ans[f];
    }
};