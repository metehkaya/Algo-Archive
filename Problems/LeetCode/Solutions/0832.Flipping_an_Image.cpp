class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m/2 ; j++ ) {
                swap(ar[i][j] , ar[i][m-j-1]);
                ar[i][j] ^= 1;
                ar[i][m-j-1] ^= 1;
            }
            if(m % 2)
                ar[i][m/2] ^= 1;
        }
        return ar;
    }
};