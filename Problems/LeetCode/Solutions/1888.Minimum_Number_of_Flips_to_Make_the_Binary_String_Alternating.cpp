class Solution {
public:
    int f(char c , int y) {
        return (c-'0')^(y&1);
    }
    int minFlips(string s) {
        int n = s.length();
        int cnt[2] = {0,0};
        for( int i = 0 ; i < n ; i++ )
            cnt[f(s[i],i)]++;
        int ans = min(cnt[0],cnt[1]);
        for( int i = 0 ; i < n ; i++ ) {
            cnt[f(s[i],i)]--;
            cnt[f(s[i],i+n)]++;
            ans = min(ans,min(cnt[0],cnt[1]));
        }
        return ans;
    }
};