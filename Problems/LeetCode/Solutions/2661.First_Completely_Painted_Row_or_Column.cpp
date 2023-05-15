class Solution {
public:
    int firstCompleteIndex(vector<int>& ar, vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        vector<vector<int>> idx(n*m+1);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                idx[mat[i][j]] = {i,j};
        vector<int> cnt_row(n,0);
        vector<int> cnt_col(m,0);
        for( int i = 0 ; i < n*m ; i++ ) {
            int r = idx[ar[i]][0] , c = idx[ar[i]][1];
            if(++cnt_row[r] == m or ++cnt_col[c] == n)
                return i;
        }
        return -1;
    }
};
