class Solution {
public:
    int add( string& sub , string& ans ) {
        if(sub.substr(0,6) == "&quot;") {
            ans.push_back('\"');
            return 6;
        }
        else if(sub.substr(0,6) == "&apos;") {
            ans.push_back('\'');
            return 6;
        }
        else if(sub.substr(0,5) == "&amp;") {
            ans.push_back('&');
            return 5;
        }
        else if(sub.substr(0,4) == "&gt;") {
            ans.push_back('>');
            return 4;
        }
        else if(sub.substr(0,4) == "&lt;") {
            ans.push_back('<');
            return 4;
        }
        else if(sub.substr(0,7) == "&frasl;") {
            ans.push_back('/');
            return 7;
        }
        ans.push_back(sub[0]);
        return 1;
    }
    string entityParser(string text) {
        string ans = "";
        int n = text.length();
        for( int i = 0 ; i < n ; i++ ) {
            int len = min( n-i , 7 );
            string sub = text.substr(i,len);
            i += add(sub,ans)-1;
        }
        return ans;
    }
};