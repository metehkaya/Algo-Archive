class Solution {
public:
    string removeDigit(string s, char digit) {
        string ans = "";
        int n = s.length();
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == digit) {
                string t = s.substr(0,i) + s.substr(i+1);
                if(ans == "")
                    ans = t;
                else
                    ans = max(ans,t);
            }
        return ans;
    }
};
