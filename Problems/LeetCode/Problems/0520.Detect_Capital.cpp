class Solution {
public:
    bool isCap(char c) {
        return c >= 'A' and c <= 'Z';
    }
    bool isAllSame(string& s) {
        bool fcs = isCap(s[0]);
        for( int i = 1 ; i < s.length() ; i++ )
            if(fcs != isCap(s[i]))
                return false;
        return true;
    }
    bool isCapStart(string& s) {
        if(!isCap(s[0]))
            return false;
        for( int i = 1 ; i < s.length() ; i++ )
            if(isCap(s[i]))
                return false;
        return true;
    }
    bool detectCapitalUse(string s) {
        return isAllSame(s) or isCapStart(s);
    }
};