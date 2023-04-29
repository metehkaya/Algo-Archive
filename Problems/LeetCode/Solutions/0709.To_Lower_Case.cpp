class Solution {
public:
    string toLowerCase(string s) {
        int n = s.length();
        for( int i = 0 ; i < n ; i++ )
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 'a' - 'A';
        return s;
    }
};