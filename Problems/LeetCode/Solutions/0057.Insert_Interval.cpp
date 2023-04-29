#define fi first
#define se second
#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;

class Solution {
public:
    vector<vector<int>> insert(vii& ar, vi& inter) {
        vector<pi> v;
        int n = ar.size();
        bool var0 = false;
        bool var1 = false;
        for( int i = 0 ; i < n ; i++ ) {
            bool added = false;
            if(!var0 && inter[0] <= ar[i][0]) {
                var0 = true;
                v.pb(pi(inter[0],+1));
            }
            if(!var1 && inter[1] < ar[i][0]) {
                var1 = true;
                added = true;
                v.pb(pi(inter[1],-1));
                v.pb(pi(ar[i][0],+1));
            }
            else if(!var1 && inter[1] == ar[i][0]) {
                var1 = true;
                added = true;
                v.pb(pi(ar[i][0],+1));
                v.pb(pi(inter[1],-1));
            }
            if(!added)
                v.pb(pi(ar[i][0],+1));
            if(!var0 && inter[0] <= ar[i][1]) {
                var0 = true;
                v.pb(pi(inter[0],+1));
            }
            if(!var1 && inter[1] <= ar[i][1]) {
                var1 = true;
                v.pb(pi(inter[1],-1));
            }
            v.pb(pi(ar[i][1],-1));
        }
        if(!var0)
            v.pb(pi(inter[0],+1));
        if(!var1)
            v.pb(pi(inter[1],-1));
        vii ans;
        int start;
        bool isOpen = false;
        for( int i = 0 , bal = 0 ; i < 2*n+2 ; i++ ) {
            if(isOpen) {
                bal += v[i].se;
                if(bal == 0) {
                    isOpen = false;
                    vector<int> add(2);
                    add[0] = start;
                    add[1] = v[i].fi;
                    ans.pb(add);
                }
            }
            else {
                bal = 1;
                isOpen = true;
                start = v[i].fi;
            }
        }
        return ans;
    }
};