#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    int maxProduct(string s) {
        int n = s.length();
        int N = (1<<n);
        vector<pi> v;
        for( int bmask = 1 ; bmask < N ; bmask++ ) {
            string t = "";
            int cnt = 0;
            for( int i = 0 ; i < n ; i++ )
                if(bmask & (1<<i)) {
                    cnt++;
                    t.pb(s[i]);
                }
            int len = t.length();
            bool ok = true;
            for( int j = 0 ; j < len ; j++ )
                if(t[j] != t[len-1-j])
                    ok = false;
            if(ok)
                v.pb(pi(bmask,cnt));
        }
        int ans = 0;
        int sz = v.size();
        for( int i = 0 ; i < sz ; i++ )
            for( int j = i+1 ; j < sz ; j++ )
                if((v[i].fi & v[j].fi) == 0)
                    ans = max(ans,v[i].se*v[j].se);
        return ans;
    }
};