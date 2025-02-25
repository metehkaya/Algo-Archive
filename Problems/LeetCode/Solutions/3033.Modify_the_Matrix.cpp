class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<int> mx(m,-1);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                mx[j] = max(mx[j],matrix[i][j]);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(matrix[i][j] == -1)
                    matrix[i][j] = mx[j];
        return matrix;
    }
};