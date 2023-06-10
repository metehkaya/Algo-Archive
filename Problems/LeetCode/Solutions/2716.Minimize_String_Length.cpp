class Solution {
public:
    int minimizedStringLength(string s) {
        set<char> chars;
        for(char c : s)
            chars.insert(c);
        return chars.size();
    }
};
