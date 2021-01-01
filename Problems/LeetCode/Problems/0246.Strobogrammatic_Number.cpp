class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.length();
        for( int i = 0 ; i < n ; i++ ) {
            int c = num[i]-'0';
            if( c == 6 && num[n-i-1] == '9' )
                continue;
            else if( c == 9 && num[n-i-1] == '6' )
                continue;
            else if( c == 8 && num[n-i-1] == '8' )
                continue;
            else if( c == 1 && num[n-i-1] == '1' )
                continue;
            else if( c == 0 && num[n-i-1] == '0' )
                continue;
            return false;
        }
        return true;
    }
};