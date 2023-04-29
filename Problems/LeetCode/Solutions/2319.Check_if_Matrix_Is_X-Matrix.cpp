class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ ) {
                bool diag = (i + j == n-1) || (i == j);
                if(diag && ar[i][j] == 0)
                    return false;
                if(!diag && ar[i][j] != 0)
                    return false;
            }
        return true;
    }
};
