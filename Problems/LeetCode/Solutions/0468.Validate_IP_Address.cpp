class Solution {
public:
    int str2num(string s) {
        int num = 0;
        int len = s.length();
        for( int i = 0 ; i < len ; i++ )
            num = num*10 + s[i]-'0';
        return num;
    }
    bool checkIP4(string s) {
        int len = s.length();
        vector<string> v;
        string curr = "";
        for( int i = 0 ; i < len ; i++ ) {
            char c = s[i];
            if(c == '.') {
                v.push_back(curr);
                curr = "";
            }
            else if(c >= '0' && c <= '9')
                curr.push_back(c);
            else
                return false;
        }
        v.push_back(curr);
        if(v.size() != 4)
            return false;
        for( int i = 0 ; i < 4 ; i++ ) {
            string str = v[i];
            int len = str.length();
            if(len == 0 || len >= 4)
                return false;
            if(len > 1 && str[0] == '0')
                return false;
            if(str2num(str) > 255)
                return false;
        }
        return true;
    }
    bool checkIP6(string s) {
        int len = s.length();
        vector<string> v;
        string curr = "";
        for( int i = 0 ; i < len ; i++ ) {
            char c = s[i];
            if(c == ':') {
                v.push_back(curr);
                curr = "";
            }
            else if(c >= '0' && c <= '9')
                curr.push_back(c);
            else if(c >= 'a' && c <= 'f')
                curr.push_back(c);
            else if(c >= 'A' && c <= 'F')
                curr.push_back(c);
            else
                return false;
        }
        v.push_back(curr);
        if(v.size() != 8)
            return false;
        for( int i = 0 ; i < 8 ; i++ ) {
            string str = v[i];
            int len = str.length();
            if(len == 0 || len > 4)
                return false;
        }
        return true;
    }
    string validIPAddress(string s) {
        string ans = "Neither";
        if(checkIP4(s))
            ans = "IPv4";
        else if(checkIP6(s))
            ans = "IPv6";
        return ans;
    }
};