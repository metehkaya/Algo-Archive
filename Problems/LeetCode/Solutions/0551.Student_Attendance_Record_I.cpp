class Solution {
public:
    bool checkRecord(string s) {
        int n = s.length();
        int nA=0,nL=0;
        for( int i = 0 ; i < n ; i++ ) {
            if( s[i] == 'A' ) {
                nA++;
                nL = 0;
                if(nA == 2)
                    return false;
            }
            else if( s[i] == 'L' ) {
                nL++;
                if(nL == 3)
                    return false;
            }
            else
                nL = 0;
        }
        return true;
    }
};