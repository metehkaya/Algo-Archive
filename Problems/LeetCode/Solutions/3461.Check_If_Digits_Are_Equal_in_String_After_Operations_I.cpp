class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length() > 2) {
            string t = "";
            int n = s.length();
            for( int i = 1 ; i < n ; i++ ) {
                int sum = (s[i-1] - '0') + (s[i] - '0');
                sum %= 10;
                t.push_back('0'+sum);
            }
            s = t;
        }
        return s[0] == s[1];
    }
};