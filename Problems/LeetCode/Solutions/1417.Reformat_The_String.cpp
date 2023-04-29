class Solution {
public:
    string reformat(string s) {
        int n = s.length();
        string digits = "";
        string letters = "";
        for( int i = 0 ; i < n ; i++ )
            if( s[i] >= '0' && s[i] <= '9' )
                digits.push_back(s[i]);
            else
                letters.push_back(s[i]);
        int nd = digits.length();
        int nl = letters.length();
        if( abs(nd-nl) > 1 )
            return "";
        string ans = "";
        if(nd >= nl) {
            for( int i = 0 ; i < nl ; i++ ) {
                ans.push_back(digits[i]);
                ans.push_back(letters[i]);
            }
            if(nd > nl)
                ans.push_back(digits[nd-1]);
        }
        else {
            for( int i = 0 ; i < nd ; i++ ) {
                ans.push_back(letters[i]);
                ans.push_back(digits[i]);
            }
            ans.push_back(letters[nl-1]);
        }
        return ans;
    }
};