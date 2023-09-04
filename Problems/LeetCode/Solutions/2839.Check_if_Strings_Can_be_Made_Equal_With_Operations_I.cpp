class Solution {
public:
    bool canBeEqual(string s, string t) {
        bool odd = (s[1] == t[1] and s[3] == t[3]) or ((s[1] == t[3] and s[3] == t[1]));
        bool even = (s[0] == t[0] and s[2] == t[2]) or ((s[0] == t[2] and s[2] == t[0]));
        return odd and even;
    }
};
