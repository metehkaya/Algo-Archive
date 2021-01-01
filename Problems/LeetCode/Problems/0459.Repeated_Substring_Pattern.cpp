class Solution {
public:
    bool check(string& s, int k) {
        int n = s.length();
        for( int i = k ; i < n ; i++ )
            if( s[i] != s[i%k] )
                return false;
        return true;
    }
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        if(n <= 1)
            return false;
        for( int i = 1 ; i <= n/2 ; i++ )
            if( n % i == 0 )
                if( check(s,i) )
                    return true;
        return false;
    }
};