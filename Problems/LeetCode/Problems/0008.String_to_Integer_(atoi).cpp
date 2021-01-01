class Solution {
public:
    int myAtoi(string str) {
        bool sign = true;
        long long ans = 0;
        int len = str.length();
        for( int i = 0 ; i < len ; i++ )
            if( str[i] != ' ' ) {
                if( str[i] == '+' )
                    i++;
                else if( str[i] == '-' )
                    sign=false, i++;
                for( int j = i ; j < len && ans < INT_MAX ; j++ ) {
                    char c = str[j];
                    if(c >= '0' && c <= '9')
                        ans = ans*10 + (c-'0');
                    else
                        break;
                }
                break;
            }
        if(!sign)
            ans = -ans;
        if(ans > INT_MAX)
            ans = INT_MAX;
        if(ans < INT_MIN)
            ans = INT_MIN;
        return (int) ans;
    }
};