class Solution {
public:
    void setZeroes(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        vector<bool> rows(n,false);
        vector<bool> cols(m,false);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if( ar[i][j] == 0 )
                    rows[i] = cols[j] = true;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if( rows[i] || cols[j] )
                    ar[i][j] = 0;
    }
};