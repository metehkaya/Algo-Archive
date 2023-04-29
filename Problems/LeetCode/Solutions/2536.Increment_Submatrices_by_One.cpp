class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<int> add1D(n+1,0);
        vector<vector<int>> add2D(n+1,vector<int>(n+1,0));
        vector<vector<int>> ans(n,vector<int>(n,0));
        for(auto q : queries) {
            int r1 = q[0] , c1 = q[1] , r2 = q[2] , c2 = q[3];
            add2D[r1][c1]++;
            add2D[r1][c2+1]--;
            add2D[r2+1][c1]--;
            add2D[r2+1][c2+1]++;
        }
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 , sum = 0 ; j < n ; j++ ) {
                add1D[j] += add2D[i][j];
                sum += add1D[j];
                ans[i][j] = sum;
            }
        return ans;
    }
};
