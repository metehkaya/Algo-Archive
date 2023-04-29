class Solution {
public:
    string modifyString(string s) {
        int n = s.length();
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == '?') {
                bool a = true , b = true;
                if(i-1 >= 0 && s[i-1] == 'a')
                    a = false;
                if(i-1 >= 0 && s[i-1] == 'b')
                    b = false;
                if(i+1 < n && s[i+1] == 'a')
                    a = false;
                if(i+1 < n && s[i+1] == 'b')
                    b = false;
                if(a)
                    s[i] = 'a';
                else if(b)
                    s[i] = 'b';
                else
                    s[i] = 'c';
            }
        return s;
    }
};