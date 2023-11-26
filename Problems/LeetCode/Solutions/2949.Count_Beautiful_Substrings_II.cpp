#define fi first
#define se second
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        long long ans = 0;
        int n = s.length();
        set<char> st({'a','e','i','o','u'});
        pii p = pii(pi(0,0),0);
        vector<int> mult;
        for( int i = 0 ; i < k ; i++ )
            if(i*i % k == 0)
                mult.push_back(i);
        map<pii,int> dp;
        dp[p] = 1;
        for( int i = 1 ; i <= n ; i++ ) {
            if(st.count(s[i-1])) {
                p.fi.fi = (p.fi.fi+1) % k;
                p.se++;
            }
            else {
                p.fi.se = (p.fi.se+1) % k;
                p.se--;
            }
            for(int diff : mult) {
                pii p2 = p;
                p2.fi.fi = (p2.fi.fi-diff+k) % k;
                p2.fi.se = (p2.fi.se-diff+k) % k;
                auto it = dp.find(p2);
                if(it != dp.end())
                    ans += it->second;
            }
            dp[p]++;
        }
        return ans;
    }
};
