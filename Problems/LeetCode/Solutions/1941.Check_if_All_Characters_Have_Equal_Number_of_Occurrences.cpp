class Solution {
public:
    int n;
    int cnt[26];
    set<int> myset;
    bool areOccurrencesEqual(string s) {
        n = s.length();
        for( int i = 0 ; i < n ; i++ ) {
            int c = s[i]-'a';
            cnt[c]++;
        }
        for( int i = 0 ; i < 26 ; i++ )
            if(cnt[i])
                myset.insert(cnt[i]);
        return (myset.size() == 1);
    }
};