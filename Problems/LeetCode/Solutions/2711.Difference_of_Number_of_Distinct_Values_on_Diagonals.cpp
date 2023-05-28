class Solution {
public:
    int n,m;
    int f(int r , int c , int dir , vector<vector<int>>& v) {
        int cnt = 0;
        vector<bool> mark(51,false);
        for( int x = r+dir , y = c+dir ; 0 <= x and x < n and 0 <= y and y < m ; x += dir , y += dir ) {
            cnt += !mark[v[x][y]];
            mark[v[x][y]] = true;
        }
        return cnt;
    }
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& v) {
        n = v.size() , m = v[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                ans[i][j] = abs(f(i,j,+1,v)-f(i,j,-1,v));
        return ans;
    }
};
