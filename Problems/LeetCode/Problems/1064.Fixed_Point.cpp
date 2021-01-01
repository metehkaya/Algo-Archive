class Solution {
public:
    int fixedPoint(vector<int>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            if(i == ar[i])
                return i;
        return -1;
    }
};