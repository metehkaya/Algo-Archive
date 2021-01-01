class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string str = "";
        for( int i = 0 ; i < n ; i++ )
            if(s[i] >= 'a' && s[i] <= 'z')
                str.push_back(s[i]);
            else if(s[i] >= 'A' && s[i] <= 'Z')
                str.push_back(s[i]+'a'-'A');
            else if(s[i] >= '0' && s[i] <= '9')
                str.push_back(s[i]);
        n = str.length();
        for( int i = 0 ; i < n/2 ; i++ )
            if(str[i] != str[n-1-i])
                return false;
        return true;
    }
};