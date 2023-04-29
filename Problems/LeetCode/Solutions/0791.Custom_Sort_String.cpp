class Solution {
public:
    string customSortString(string S, string T) {
        int n = S.length();
        int m = T.length();
        int cnt[26] = {0};
        for( int i = 0 ; i < m ; i++ )
            cnt[T[i]-'a']++;
        string ans = "";
        for( int i = 0 ; i < n ; i++ ) {
            int c = S[i]-'a';
            for( int j = 0 ; j < cnt[c] ; j++ )
                ans = ans + S[i];
            cnt[c] = 0;
        }
        for( int i = 0 ; i < 26 ; i++ )
            for( int j = 0 ; j < cnt[i] ; j++ )
                ans = ans + (char)('a' + i);
        return ans;
    }
};