class Solution {
public:
    bool check(string s) {
        for( int i = 0 ; i < s.length() ; i++ )
            if(s[i] == '@')
                return true;
        return false;
    }
    string f(string& s) {
        s.push_back('.');
        int len = s.length();
        string ans = "";
        for( int i = 0 , k = 0 ; k < 3 ; k++ ) {
            string word = "";
            while((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
                if(s[i] >= 'A' && s[i] <= 'Z')
                    word.push_back(s[i++]-'A'+'a');
                else
                    word.push_back(s[i++]);
            }
            char c = s[i++];
            int sz = word.length();
            if(k == 0) {
                string wnew = "";
                wnew.push_back(word[0]);
                wnew += "*****";
                wnew.push_back(word[sz-1]);
                word = wnew;
            }
            ans += word;
            if(k < 2)
                ans.push_back(c);
        }
        return ans;
    }
    string g(string& s) {
        int len = s.length();
        string digits = "";
        for( int i = 0 ; i < len ; i++ )
            if(s[i] >= '0' && s[i] <= '9')
                digits.push_back(s[i]);
        int cnt = digits.length();
        string last4 = digits.substr(cnt-4,4);
        string ans = "";
        if(cnt > 10) {
            ans = "+";
            for( int i = 10 ; i < cnt ; i++ )
                ans.push_back('*');
            ans.push_back('-');
        }
        ans += "***-***-" + last4;
        return ans;
    }
    string maskPII(string s) {
        string ans;
        if(check(s))
            ans = f(s);
        else
            ans = g(s);
        return ans;
    }
};