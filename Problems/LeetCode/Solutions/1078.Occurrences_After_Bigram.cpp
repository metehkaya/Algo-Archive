class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string word1 = "";
        string word2 = "";
        string word3 = "";
        vector<string> ans;
        text.push_back(' ');
        int len = text.length();
        for( int i = 0 ; i < len ; i++ ) {
            char c = text[i];
            if(c == ' ') {
                if(first == word1 && second == word2)
                    ans.push_back(word3);
                word1 = word2;
                word2 = word3;
                word3 = "";
            }
            else
                word3.push_back(c);
        }
        return ans;
    }
};