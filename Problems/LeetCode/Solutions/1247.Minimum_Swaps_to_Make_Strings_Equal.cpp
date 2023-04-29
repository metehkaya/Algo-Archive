class Solution {
public:
    int minimumSwap(string s, string t) {
        int n = s.length();
        int xy = 0 , yx = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == 'x' && t[i] == 'y')
                xy++;
            else if(s[i] == 'y' && t[i] == 'x')
                yx++;
        }
        if(abs(xy-yx) % 2)
            return -1;
        return (xy+1)/2 + (yx+1)/2;
    }
};