class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        int bmask = 0;
        for(char c : s)
            if(c == '1')
                bmask |= 1;
        for(char c : t)
            if(c == '1')
                bmask |= 2;
        return bmask == 0 or bmask == 3;
    }
};
