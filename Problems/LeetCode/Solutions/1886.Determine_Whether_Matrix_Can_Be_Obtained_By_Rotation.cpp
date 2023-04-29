class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for( int times = 0 ; times < 4 ; times++ ) {
            vector< vector<int> > temp(n , vector<int>(n));
            for( int i = 0 ; i < n ; i++ )
                for( int j = 0 ; j < n ; j++ )
                    temp[j][n-1-i] = mat[i][j];
            mat = temp;
            bool same = true;
            for( int i = 0 ; i < n ; i++ )
                for( int j = 0 ; j < n ; j++ )
                    if(mat[i][j] != target[i][j])
                        same = false;
            if(same)
                return true;
        }
        return false;
    }
};