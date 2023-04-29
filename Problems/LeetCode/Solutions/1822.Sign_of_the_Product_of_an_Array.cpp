class Solution {
public:
    int arraySign(vector<int>& ar) {
        int n = ar.size();
        int mult = 1;
        for( int i = 0 ; i < n ; i++ ) {
            if(ar[i] == 0) {
                mult = 0;
                break;
            }
            else if(ar[i] < 0)
                mult = -mult;
        }
        return mult;
    }
};