class Solution {
public:
    int cnt[1024];
    long long wonderfulSubstrings(string s) {
        int n = s.length();
        int curr = 0;
        cnt[0] = 1;
        long long ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int c = s[i]-'a';
            int bmask = (1<<c);
            curr ^= bmask;
            ans += cnt[curr];
            for( int j = 0 ; j < 10 ; j++ ) {
                int temp = (curr ^ (1<<j));
                ans += cnt[temp];
            }
            cnt[curr]++;
        }
        return ans;
    }
};