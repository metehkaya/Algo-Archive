#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    int longestBeautifulSubstring(string s) {
        int n = s.length();
        vector<pi> v;
        int idx[256];
        idx['a'] = 1 , idx['e'] = 2 , idx['i'] = 3 , idx['o'] = 4 , idx['u'] = 5;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && s[i] == s[j])
                j++;
            v.pb(pi(idx[s[i]],j-i));
        }
        int ans = 0;
        n = v.size();
        for( int i = 0 ; i <= n-5 ; i++ ) {
            int sum = 0;
            bool ok = true;
            for( int j = 0 ; j < 5 ; j++ ) {
                sum += v[i+j].se;
                if(v[i+j].fi != j+1)
                    ok = false;
            }
            if(ok)
                ans = max(ans,sum);
        }
        return ans;
    }
};