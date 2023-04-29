class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length();
        int ans = 0;
        int pwr[n];
        pwr[0] = 1;
        for( int i = 1 ; i < n ; i++ )
            pwr[i] = pwr[i-1] * 26;
        for( int i = 1 ; i < n ; i++ )
            ans += pwr[i];
        for( int i = 0 ; i < n ; i++ )
            ans += pwr[n-i-1] * (s[i] - 'A');
        return ans+1;
    }
};