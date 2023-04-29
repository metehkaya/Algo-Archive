class Solution {
public:
    bool areAlmostEqual(string s, string t) {
        int n = s.length();
        if(s == t)
            return true;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ ) {
                swap(s[i],s[j]);
                if(s == t)
                    return true;
                swap(s[i],s[j]);
            }
        return false;
    }
};