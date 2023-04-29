class Solution {
public:
    bool isCircularSentence(string s) {
        s.push_back(' ');
        int n = s.length();
        string word = "";
        vector<string> words;
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == ' ') {
                words.push_back(word);
                word = "";
            }
            else
                word.push_back(s[i]);
        }
        n = words.size();
        for( int i = 1 ; i < n ; i++ )
            if(words[i][0] != words[i-1][words[i-1].length()-1])
                return false;
        if(words[0][0] != words[n-1][words[n-1].length()-1])
            return false;
        return true;
    }
};
