class Solution {
public:
    void generateString(string word, string& str, int& n, vector<bool>& mark, unordered_set<string>& allWords) {
        if(word != "")
            allWords.insert(word);
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i]) {
                mark[i] = true;
                generateString(word+str[i],str,n,mark,allWords);
                mark[i] = false;
            }
    }
    int numTilePossibilities(string str) {
        unordered_set<string> allWords;
        int n = str.length();
        vector<bool> mark(n,false);
        generateString("",str,n,mark,allWords);
        return allWords.size();
    }
};