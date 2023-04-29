class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& ar, int r, int c) {
        int n = ar.size();
        int m = ar[0].size();
        if(n*m != r*c)
            return ar;
        vector<vector<int>> ans;
        for( int i = 0 ; i < r ; i++ ) {
            vector<int> row;
            for( int j = 0 ; j < c ; j++ ) {
                int id = c*i+j;
                int x = id/m;
                int y = id%m;
                row.push_back(ar[x][y]);
            }
            ans.push_back(row);
        }
        return ans;
    }
};