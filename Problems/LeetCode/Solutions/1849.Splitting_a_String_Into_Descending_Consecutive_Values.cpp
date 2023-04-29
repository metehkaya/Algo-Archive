typedef unsigned long long ull;

class Solution {
public:
    bool splitString(string s) {
        ull f = 0;
        int n = s.length();
        for( int k = 1 ; k <= n-1 ; k++ ) {
            bool ok = true;
            f = 10*f + (s[k-1]-'0');
            ull exp = f-1;
            for( int i = k , j = k ; i < n ; i = j , exp-- ) {
                if(exp == 0) {
                    while(j < n && s[j] == '0')
                        j++;
                    ok = (j == n);
                    break;
                }
                ull num = 0;
                num = s[j++]-'0';
                while(j < n && num < exp)
                    num = 10*num + (s[j++]-'0');
                if(num != exp) {
                    ok = false;
                    break;
                }
            }
            if(ok)
                return true;
        }
        return false;
    }
};