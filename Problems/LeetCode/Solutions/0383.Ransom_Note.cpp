class Solution {
public:
    bool canConstruct(string s, string t) {
        vector<int> cnt(26,0);
        int n = s.length();
        int m = t.length();
        for( int i = 0 ; i < m ; i++ )
            cnt[t[i]-'a']++;
        for( int i = 0 ; i < n ; i++ )
            if(!cnt[s[i]-'a'])
                return false;
            else
                cnt[s[i]-'a']--;
        return true;
    }
};