class Solution {
public:
    int maxRepeating(string s, string t) {
        int n = s.length();
        int m = t.length();
        int ans = 0;
        for( int i = 0 ; i <= n-m ; i++ ) {
            int cnt;
            for( cnt = 0 ; cnt < n-i ; cnt++ )
                if(s[i+cnt] != t[cnt%m])
                    break;
            ans = max(ans,cnt/m);
        }
        return ans;
    }
};