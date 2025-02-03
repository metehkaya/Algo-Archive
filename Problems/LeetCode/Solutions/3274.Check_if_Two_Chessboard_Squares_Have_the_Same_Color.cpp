class Solution {
public:
    bool checkTwoChessboards(string s1, string s2) {
        int p1 = s1[0]-'a' + s1[1]-'1';
        int p2 = s2[0]-'a' + s2[1]-'1';
        return p1%2 == p2%2;
    }
};