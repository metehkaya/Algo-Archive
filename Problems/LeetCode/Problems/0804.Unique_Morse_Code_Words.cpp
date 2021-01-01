class Solution {
public:
    string words[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& ar) {
        set<string> s;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            string str = "";
            int len = ar[i].length();
            for( int j = 0 ; j < len ; j++ ) {
                int c = ar[i][j]-'a';
                int len2 = words[c].length();
                for( int k = 0 ; k < len2 ; k++ )
                    str.push_back(words[c][k]);
            }
            s.insert(str);
        }
        return s.size();
    }
};