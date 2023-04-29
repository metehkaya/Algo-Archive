class Solution {
public:
    bool squareIsWhite(string s) {
        int x = s[0]-'a' + s[1]-'0';
        return 1-x%2;
    }
};