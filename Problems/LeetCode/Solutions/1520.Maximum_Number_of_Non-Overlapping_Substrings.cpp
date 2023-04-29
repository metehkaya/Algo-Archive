#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> mn(26,INT_MAX);
        vector<int> mx(26,INT_MIN);
        for( int i = 0 ; i < n ; i++ ) {
            int c = s[i]-'a';
            if(mn[c] == INT_MAX)
                mn[c] = i;
            mx[c] = i;
        }
        vector<pi> v;
        for( int i = 0 ; i < 26 ; i++ )
            if(mn[i] != INT_MAX) {
                int st = mn[i];
                int en = mx[i];
                int l = st , r = st;
                while(l > st or r < en) {
                    int c;
                    if(l > st)
                        c = s[l--]-'a';
                    else
                        c = s[r++]-'a';
                    st = min(st,mn[c]);
                    en = max(en,mx[c]);
                }
                v.push_back(pi(st,en));
            }
        int k = v.size();
        sort(v.begin() , v.end() , [](pi a , pi b) {
            return a.se < b.se;
        });
        vector<pi> dp(k);
        vector<int> best(k,-1);
        for( int i = 0 ; i < k ; i++ ) {
            dp[i] = pi(1,v[i].se-v[i].fi);
            for( int j = 0 ; j < i ; j++ )
                if(v[j].se < v[i].fi) {
                    int a = dp[j].fi + 1;
                    int b = dp[j].se + v[i].se - v[i].fi;
                    if(a > dp[i].fi or (a == dp[i].fi and b < dp[i].se)) {
                        dp[i] = pi(a,b);
                        best[i] = j;
                    }
                }
        }
        int last = 0;
        for( int i = 1 ; i < k ; i++ )
            if(dp[i].fi > dp[last].fi or (dp[i].fi == dp[last].fi and dp[i].se < dp[last].se))
                last = i;
        vector<string> ans;
        while(last != -1) {
            int st = v[last].fi;
            int en = v[last].se;
            string word = s.substr(st,en-st+1);
            ans.push_back(word);
            last = best[last];
        }
        return ans;
    }
};