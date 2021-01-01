class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.length();
        int m = t.length();
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                int cnt = 0;
                for( int k = 0 ; i+k < n && j+k < m ; k++ ) {
                    cnt += (s[i+k] != t[j+k]);
                    if(cnt == 1)
                        ans++;
                    else if(cnt > 1)
                        break;
                }
            }
        return ans;
    }
};