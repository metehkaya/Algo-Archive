class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans = "";
        int len = s.length();
        for( int i = 0 ; i <= len ; i++ ) {
            if(i == len || s[i] == ' ')
                if(--k == 0)
                    break;
            ans.push_back(s[i]);
        }
        return ans;
    }
};