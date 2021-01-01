class Solution {
public:
    string defangIPaddr(string s) {
        int n = s.length();
        string ans = "";
        for( int i = 0 ; i < n ; i++ ) {
            char c = s[i];
            if(c == '.')
                ans += "[.]";
            else
                ans.push_back(c);
        }
        return ans;
    }
};