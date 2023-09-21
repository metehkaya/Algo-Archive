class Solution {
public:
    int n;
    int dir[4] = {0,1,0,-1};
    void dfs(int r , int c , long long& sum , int& cnt , vector<vector<int>>& grid) {
        cnt++;
        sum += grid[r][c];
        grid[r][c] = 0;
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r+dir[i] , y = c+dir[i^1];
            if(x < 0 or x >= n or y < 0 or y >= n or grid[x][y] <= 0)
                continue;
            dfs(x,y,sum,cnt,grid);
        }
    }
    long long sumRemoteness(vector<vector<int>>& grid) {
        long long total = 0 , ans = 0;
        n = grid.size();
        vector<int> cnts;
        vector<long long> sums;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                if(grid[i][j] > 0) {
                    int cnt = 0;
                    long long sum = 0;
                    dfs(i,j,sum,cnt,grid);
                    total += sum;
                    cnts.push_back(cnt);
                    sums.push_back(sum);
                }
        int g = cnts.size();
        for( int i = 0 ; i < g ; i++ ) {
            int cnt = cnts[i];
            long long sum = sums[i];
            ans += cnt * (total-sum);
        }
        return ans;
    }
};
