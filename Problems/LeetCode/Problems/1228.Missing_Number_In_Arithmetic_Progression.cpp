class Solution {
public:
    int missingNumber(vector<int>& ar) {
        int n = ar.size();
        int diff1 = ar[1] - ar[0];
        int diff2 = ar[2] - ar[1];
        int diff;
        if( abs(diff1) < abs(diff2) )
            diff = diff1;
        else
            diff = diff2;
        for( int i = 0 ; i < n-1 ; i++ )
            if( ar[i+1] - ar[i] != diff )
                return ar[i] + diff;
        return ar[0];
    }
};