class Solution {
public:
    bool wordPattern(string p, string s) {
        int n = p.length();
        s.push_back(' ');
        int len = s.length();
        vector<string> words;
        string word = "";
        for( int i = 0 ; i < len ; i++ ) {
            if(s[i] == ' ') {
                if(!word.empty())
                    words.push_back(word);
                word = "";
            }
            else
                word.push_back(s[i]);
        }
        if(n != words.size())
            return false;
        map<string,char> idx;
        map<string,char>::iterator it;
        vector<bool> mark(256,false);
        for( int i = 0 ; i < n ; i++ ) {
            it = idx.find(words[i]);
            if(it == idx.end()) {
                if(mark[(int)p[i]])
                    return false;
                idx[words[i]] = p[i];
                mark[(int)p[i]] = true;
            }
            else if(it->second != p[i])
                    return false;
        }
        return true;
    }
};