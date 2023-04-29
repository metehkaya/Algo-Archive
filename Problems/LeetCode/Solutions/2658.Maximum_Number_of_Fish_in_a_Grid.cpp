class Solution {
public:
    int n,m;
    int dir[4] = {0,1,0,-1};
    void dfs(int r , int c , vector<vector<int>>& grid , int& sum) {
        sum += grid[r][c];
        grid[r][c] = 0;
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r+dir[i];
            int y = c+dir[i^1];
            if(x < 0 or y < 0 or x >= n or y >= m)
                continue;
            if(!grid[x][y])
                continue;
            dfs(x,y,grid,sum);
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size() , m = grid[0].size();
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(grid[i][j]) {
                    int sum = 0;
                    dfs(i,j,grid,sum);
                    ans = max(ans,sum);
                }
        return ans;
    }
};
