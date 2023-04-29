class Solution {
public:
    const int DIR[4][2] = { {0,-1} , {0,+1} , {-1,0} , {+1,0} };
    void dfs(int r, int c, vector<vector<char>>& ar, vector<vector<bool>>& mark) {
        mark[r][c] = true;
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r+DIR[i][0];
            int y = c+DIR[i][1];
            if( x < 0 || x >= ar.size() || y < 0 || y >= ar[0].size() )
                continue;
            if( mark[x][y] || ar[x][y] == '0' )
                continue;
            dfs(x,y,ar,mark);
        }
    }
    int numIslands(vector<vector<char>>& ar) {
        int n = ar.size();
        if(n == 0)
            return 0;
        int m = ar[0].size();
        if(m == 0)
            return 0;
        int ans = 0;
        vector<vector<bool>> mark(n, vector<bool>(m));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if( ar[i][j] == '1' && !mark[i][j] ) {
                    ans++;
                    dfs(i,j,ar,mark);
                }
        return ans;
    }
};