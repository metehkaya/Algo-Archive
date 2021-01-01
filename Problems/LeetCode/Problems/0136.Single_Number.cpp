class Solution {
public:
    int singleNumber(vector<int>& ar) {
        int n = ar.size(), res = 0;
        for( int i = 0 ; i < n ; i++ )
            res ^= ar[i];
        return res;
    }
};