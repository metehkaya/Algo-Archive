class Solution {
public:
    void rotate(vector<vector<int>>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < (n+1)/2 ; i++ )
            for( int j = 0 ; j < n/2 ; j++ ) {
                int temp = ar[n-1-j][i];
                ar[n-1-j][i] = ar[n-1-i][n-j-1];
                ar[n-1-i][n-j-1] = ar[j][n-1-i];
                ar[j][n-1-i] = ar[i][j];
                ar[i][j] = temp;
            }
    }
};