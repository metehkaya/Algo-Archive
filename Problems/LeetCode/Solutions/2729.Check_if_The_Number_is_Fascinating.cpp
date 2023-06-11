class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n) + to_string(2*n) + to_string(3*n);
        int bmask = 0;
        for(char c : s)
            bmask |= (1 << (c-'0'));
        return s.length() == 9 and bmask == 1022;
    }
};
