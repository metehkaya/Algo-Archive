class Solution {
public:
    int countTime(string time) {
        int a = 0 , b = 0;
        for( int i = 0 ; i < 24 ; i++ ) {
            string s = time.substr(0,2);
            if((s[0] == '?' || i/10 == s[0]-'0') && (s[1] == '?' || i%10 == s[1]-'0'))
                a++;
        }
        for( int i = 0 ; i < 60 ; i++ ) {
            string s = time.substr(3,2);
            if((s[0] == '?' || i/10 == s[0]-'0') && (s[1] == '?' || i%10 == s[1]-'0'))
                b++;
        }
        return a*b;
    }
};
