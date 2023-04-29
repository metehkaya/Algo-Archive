class Solution {
public:
    string reformatNumber(string number) {
        int len = number.length();
        string s = "";
        for( int i = 0 ; i < len ; i++ ) {
            char c = number[i];
            if(c >= '0' && c <= '9')
                s.push_back(c);
        }
        string ans = "";
        len = s.length();
        for( int i = 0 ; i < len ; i++ ) {
            if(i % 3 == 0) {
                if(i)
                    ans.push_back('-');
                if(len-i >= 2 && len-i <= 4) {
                    if(len - i == 2) {
                        ans.push_back(s[i]);
                        ans.push_back(s[i+1]);
                    }
                    else if(len - i == 3) {
                        ans.push_back(s[i]);
                        ans.push_back(s[i+1]);
                        ans.push_back(s[i+2]);
                    }
                    else {
                        ans.push_back(s[i]);
                        ans.push_back(s[i+1]);
                        ans.push_back('-');
                        ans.push_back(s[i+2]);
                        ans.push_back(s[i+3]);
                    }
                    break;
                }
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};