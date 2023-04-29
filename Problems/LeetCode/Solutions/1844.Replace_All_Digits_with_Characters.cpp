class Solution {
public:
    string replaceDigits(string s) {
        int len = s.length();
        for( int i = 1 ; i < len ; i += 2 ) {
            char c = s[i-1];
            int d = s[i]-'0';
            s[i] = c+d;
        }
        return s;
    }
};