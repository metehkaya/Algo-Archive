class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string t;
        for(string w : words)
            t.push_back(w[0]);
        return s==t;
    }
};