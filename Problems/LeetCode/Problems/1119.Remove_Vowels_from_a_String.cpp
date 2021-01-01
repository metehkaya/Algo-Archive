class Solution {
public:
    string removeVowels(string s) {
        int n = s.length();
        string ans = "";
        for( int i = 0 ; i < n ; i++ ) {
            char c = s[i];
            if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
                continue;
            ans.push_back(c);
        }
        return ans;
    }
};