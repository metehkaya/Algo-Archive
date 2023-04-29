class Solution {
public:
    int n;
    int cnt[2] = {0,0};
    int total[2] = {0,0};
    long long numberOfWays(string s) {
        n = s.length();
        for( int i = 0 ; i < n ; i++ )
            total[s[i]-'0']++;
        long long ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int c = s[i]-'0';
            int l = cnt[!c];
            int r = total[!c] - cnt[!c];
            ans += (long long) l*r;
            cnt[c]++;
        }
        return ans;
    }
};
