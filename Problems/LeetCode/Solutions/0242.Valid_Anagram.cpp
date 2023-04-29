class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26] = {0};
        for( int i = 0 ; i < s.length() ; i++ )
            cnt[s[i]-'a']++;
        for( int i = 0 ; i < t.length() ; i++ )
            cnt[t[i]-'a']--;
        for( int i = 0 ; i < 26 ; i++ )
            if(cnt[i] != 0)
                return false;
        return true;
    }
};