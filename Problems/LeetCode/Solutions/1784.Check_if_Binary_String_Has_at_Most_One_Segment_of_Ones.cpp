class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        int idx = 0;
        while(idx < n && s[idx] == '1')
            idx++;
        for( int i = idx ; i < n ; i++ )
            if(s[i] == '1')
                return false;
        return true;
    }
};