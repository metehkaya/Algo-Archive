class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string curr = "";
        string ans = "";
        for( int i = 0 ; i < n ; i++ ) {
            char c = s[i];
            if(iswspace(c)) {
                if(curr != "") {
                    reverse(curr.begin(), curr.end());
                    ans.append(curr);
                    curr = "";
                }
                ans.push_back(c);
            }
            else
                curr.push_back(c);
        }
        if(curr != "") {
            reverse(curr.begin(), curr.end());
            ans.append(curr);
        }
        return ans;
    }
};