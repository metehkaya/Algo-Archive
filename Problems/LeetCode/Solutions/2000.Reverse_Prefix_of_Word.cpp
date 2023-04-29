class Solution {
public:
    string reversePrefix(string s, char ch) {
        int n = s.length();
        int idx = -1;
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == ch) {
                idx = i;
                break;
            }
        if(idx == -1)
            return s;
        reverse(s.begin(),s.begin()+idx+1);
        return s;
    }
};