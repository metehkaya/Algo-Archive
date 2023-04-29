class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        string spec = "!@#$%^&*()-+";
        int m = spec.length();
        int n = s.length();
        if(n < 8)
            return false;
        int cond = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] >= 'a' && s[i] <= 'z')
                cond |= 1;
            if(s[i] >= 'A' && s[i] <= 'Z')
                cond |= 2;
            if(s[i] >= '0' && s[i] <= '9')
                cond |= 4;
            if(i > 0 && s[i] == s[i-1])
                return false;
            for( int j = 0 ; j < m ; j++ )
                if(s[i] == spec[j])
                    cond |= 8;
        }
        return (cond == 15);
    }
};
