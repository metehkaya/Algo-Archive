class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int pos = 0 , add = 0;
        for(char c : moves) {
            if(c == 'L')
                pos--;
            else if(c == 'R')
                pos++;
            else
                add++;
        }
        return abs(pos)+add;
    }
};
