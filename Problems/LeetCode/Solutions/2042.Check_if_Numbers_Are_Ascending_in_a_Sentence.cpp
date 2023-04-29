class Solution {
public:
    bool areNumbersAscending(string s) {
        s.push_back(' ');
        int n = s.length();
        int last = -1 , num = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == ' ') {
                if(num >= 0) {
                    if(num <= last)
                        return false;
                    last = num;
                }
                num = 0;
            }
            else if(s[i] >= '0' && s[i] <= '9')
                num = 10*num + (s[i]-'0');
            else
                num = -1;
        }
        return true;
    }
};
