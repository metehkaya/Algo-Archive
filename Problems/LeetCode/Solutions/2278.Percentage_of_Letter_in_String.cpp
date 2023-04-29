class Solution {
public:
    int percentageLetter(string s, char c) {
        int n = s.length() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            ans += (s[i] == c);
        return ans*100/n;
    }
};
