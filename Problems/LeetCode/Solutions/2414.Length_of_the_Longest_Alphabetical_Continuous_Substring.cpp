class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 0 , n = s.length();
        for( int i = 0 ; i < n ; i++ ) {
            int cnt = 0;
            while(cnt < 26 && i+cnt < n && s[i+cnt] == s[i]+cnt)
                cnt++;
            ans = max(ans,cnt);
        }
        return ans;
    }
};
