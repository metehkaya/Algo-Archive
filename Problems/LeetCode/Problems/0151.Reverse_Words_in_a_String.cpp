class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        vector<string> v;
        string word = "";
        for( int i = 0 ; i < s.length() ; i++ ) {
            char c = s[i];
            if(c == ' ') {
                if(word != "") {
                    v.push_back(word);
                    word = "";
                }
            }
            else
                word.push_back(c);
        }
        string ans = "";
        for( int i = v.size()-1 ; i >= 0 ; i-- ) {
            if(ans != "")
                ans.push_back(' ');
            ans += v[i];
        }
        return ans;
    }
};