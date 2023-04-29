class Solution {
public:
    int n,m;
    vector<vector<int>> ar;
    int dir[4] = {0,1,0,-1};
    void dfs(int r , int c , int& cnt) {
        cnt++;
        ar[r][c] = 0;
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r + dir[i];
            int y = c + dir[i^1];
            if(x >= 0 && x < n && y >= 0 && y < m)
                if(ar[x][y])
                    dfs(x,y,cnt);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        ar = grid;
        n = ar.size();
        m = ar[0].size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j]) {
                    int cnt = 0;
                    dfs(i,j,cnt);
                    ans = max(ans,cnt);
                }
        return ans;
    }
};