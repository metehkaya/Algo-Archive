class Solution {
public:
    int dayOfYear(string s) {
        int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int y = 0 , m = 0 , d = 0;
        for( int i = 0 ; i < 4 ; i++ )
            y = 10*y + s[i]-'0';
        for( int i = 5 ; i < 7 ; i++ )
            m = 10*m + s[i]-'0';
        for( int i = 8 ; i < 10 ; i++ )
            d = 10*d + s[i]-'0';
        if( y%400 == 0 || y%4 == 0 && y%100 != 0 )
            days[1]++;
        int ans = d;
        for( int i = 0 ; i < m-1 ; i++ )
            ans += days[i];
        return ans;
    }
};