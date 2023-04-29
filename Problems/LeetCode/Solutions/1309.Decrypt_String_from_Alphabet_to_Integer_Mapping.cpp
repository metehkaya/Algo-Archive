class Solution {
public:
    string freqAlphabets(string s) {
        string t;
        int n = (int) s.length();
        for( int i = 0 ; i < n ; i++ ) {
            if( i+3 <= n && s[i+2] == '#' ) {
                int val = 10 * (s[i]-'0') + s[i+1]-'0' - 1;
                char c = 'a' + val;
                t += c;
                i += 2;
            }
            else {
                char c = s[i]-'0'+'a'-1;
                t += c;
            }
        }
        return t;
    }
};