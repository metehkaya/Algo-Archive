class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& ar, int k) {
        int n = ar.size();
        int m = ar[0].size();
        vector<int> res(n*m);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                res[(i*m+j+k)%(n*m)] = ar[i][j];
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                ar[i][j] = res[i*m+j];
        return ar;
    }
};