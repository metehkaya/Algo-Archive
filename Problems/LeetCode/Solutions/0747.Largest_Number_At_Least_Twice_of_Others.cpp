class Solution {
public:
    int dominantIndex(vector<int>& ar) {
        int n = ar.size();
        int val1 = 0 , idx1 = -1;
        int val2 = 0 , idx2 = -1;
        for( int i = 0 ; i < n ; i++ ) {
            int val = ar[i];
            if(val >= val1) {
                val2 = val1 , idx2 = idx1;
                val1 = val , idx1 = i;
            }
            else if(val >= val2)
                val2 = val , idx2 = i;
        }
        return (val1 >= 2*val2) ? idx1 : -1;
    }
};