class Solution {
public:
    bool checkAlmostEquivalent(string s, string t) {
        vector<int> cnt(26,0);
        for( int i = 0 ; i < s.length() ; i++ )
            cnt[s[i]-'a']++;
        for( int i = 0 ; i < t.length() ; i++ )
            cnt[t[i]-'a']--;
        for( int i = 0 ; i < 26 ; i++ )
            if(abs(cnt[i]) > 3)
                return false;
        return true;
    }
};
