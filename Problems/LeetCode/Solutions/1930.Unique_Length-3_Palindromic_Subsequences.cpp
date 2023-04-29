class Solution {
public:
    int n;
    static const int maxn = 100000;
    bool res[26][26];
    bool pref[maxn][26];
    bool suff[maxn][26];
    int countPalindromicSubsequence(string s) {
        n = s.length();
        pref[0][s[0]-'a'] = true;
        for( int i = 1 ; i < n ; i++ )
            for( int j = 0 ; j < 26 ; j++ )
                pref[i][j] = pref[i-1][j] || (j == s[i]-'a');
        suff[n-1][s[n-1]-'a'] = true;
        for( int i = n-2 ; i >= 0 ; i-- )
            for( int j = 0 ; j < 26 ; j++ )
                suff[i][j] = suff[i+1][j] || (j == s[i]-'a');
        for( int i = 1 ; i < n-1 ; i++ ) {
            int c = s[i]-'a';
            for( int j = 0 ; j < 26 ; j++ )
                if(pref[i-1][j] && suff[i+1][j])
                    res[c][j] = true;
        }
        int ans = 0;
        for( int i = 0 ; i < 26 ; i++ )
            for( int j = 0 ; j < 26 ; j++ )
                ans += res[i][j];
        return ans;
    }
};