class Solution {
public:
    int cnt[2];
    string vowel = "aeiouAEIOU";
    bool halvesAreAlike(string s) {
        int n = s.length();
        for( int i = 0 ; i < n ; i++ ) {
            bool ok = false;
            for( int j = 0 ; j < 10 ; j++ )
                if(s[i] == vowel[j])
                    ok = true;
            if(ok)
                cnt[i/(n/2)]++;
        }
        return cnt[0] == cnt[1];
    }
};