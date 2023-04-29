class Solution {
public:
    bool check(string& s) {
        int n = s.length();
        int var[26][2];
        memset(var,0,sizeof(var));
        for( int i = 0 ; i < n ; i++ )
            if(s[i] >= 'a')
                var[s[i]-'a'][0] = 1;
            else
                var[s[i]-'A'][1] = 1;
        for( int i = 0 ; i < 26 ; i++ )
            if(var[i][0] + var[i][1] == 1)
                return false;
        return true;
    }
    string longestNiceSubstring(string s) {
        int n = s.length();
        for( int len = n ; len >= 1 ; len-- ) {
            for( int i = 0 ; i <= n-len ; i++ ) {
                string t = s.substr(i,len);
                if(check(t))
                    return t;
            }
        }
        return "";
    }
};