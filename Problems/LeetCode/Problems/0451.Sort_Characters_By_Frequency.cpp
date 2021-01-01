#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    const int K = 256;
    string frequencySort(string s) {
        int n = s.length();
        vector<pi> cnt(K);
        for( int i = 0 ; i < K ; i++ )
            cnt[i] = pi(0,i);
        for( int i = 0 ; i < n ; i++ )
            cnt[s[i]].fi++;
        sort(cnt.begin(), cnt.end());
        string ans = "";
        for( int i = K-1 ; i>= 0 ; i-- ) {
            char c = cnt[i].se;
            for( int j = 0 ; j < cnt[i].fi ; j++ )
                ans.push_back(c);
        }
        return ans;
    }
};