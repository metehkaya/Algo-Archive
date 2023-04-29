class Solution {
public:
    string interpret(string s) {
        string ans = "";
        int n = s.length();
        for( int i = 0 ; i < n ; ) {
            if(s[i] == 'G')
                ans.push_back(s[i++]);
            else if(s[i+1] == ')') {
                ans.push_back('o');
                i += 2;
            }
            else {
                ans.push_back('a');
                ans.push_back('l');
                i += 4;
            }
        }
        return ans;
    }
};