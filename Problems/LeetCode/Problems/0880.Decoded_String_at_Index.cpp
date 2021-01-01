class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n = s.length();
        long long total = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] >= '2' && s[i] <= '9')
                total *= s[i]-'0';
            else
                total++;
        }
        for( int i = n-1 ; i >= 0 ; i-- ) {
            k %= total;
            if(k == 0 && !isdigit(s[i]))
                return (string)""+s[i];
            if(!isdigit(s[i]))
                total--;
            else
                total /= s[i]-'0';
        }
        return "";
    }
};