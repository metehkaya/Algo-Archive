class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length();
        vector<int> cnt(26,0);
        for( int i = 0 ; i < n ; i++ )
            cnt[s[i]-'a']++;
        for( int i = 0 ; i <= n ; i++ )
            if(cnt[t[i]-'a']-- == 0)
                return t[i];
        return '?';
    }
};