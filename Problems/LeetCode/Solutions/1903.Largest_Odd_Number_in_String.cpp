class Solution {
public:
    string largestOddNumber(string s) {
        int last = 0;
        int n = s.length();
        for( int i = n-1 ; i >= 0 ; i-- ) {
            int d = s[i]-'0';
            if(d%2) {
                last = i+1;
                break;
            }
        }
        return s.substr(0,last);
    }
};