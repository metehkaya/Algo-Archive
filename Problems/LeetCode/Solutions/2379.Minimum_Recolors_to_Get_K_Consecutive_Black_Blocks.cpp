class Solution {
public:
    int minimumRecolors(string s, int k) {
        int cnt = 0;
        int n = s.length();
        for( int i = 0 ; i < k ; i++ )
            if(s[i] == 'W')
                cnt++;
        int ans = cnt;
        for( int i = k ; i < n ; i++ ) {
            if(s[i-k] == 'W')
                cnt--;
            if(s[i] == 'W')
                cnt++;
            ans = min(ans,cnt);
        }
        return ans;
    }
};
