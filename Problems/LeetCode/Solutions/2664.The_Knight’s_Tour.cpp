class Solution {
public:
    int n,m;
    int dir[8][2] = {{1,2},{2,1},{1,-2},{2,-1},{-1,2},{-2,1},{-1,-2},{-2,-1}};
    bool dfs(int r , int c , int cnt , vector<vector<int>>& ans) {
        if(cnt == n*m)
            return true;
        for( int i = 0 ; i < 8 ; i++ ) {
            int x = r+dir[i][0] , y = c+dir[i][1];
            if(x < 0 or x >= n or y < 0 or y >= m or ans[x][y] != -1)
                continue;
            ans[x][y] = cnt;
            if(dfs(x,y,cnt+1,ans))
                return true;
            ans[x][y] = -1;
        }
        return false;
    }
    vector<vector<int>> tourOfKnight(int n, int m, int r, int c) {
        this->n = n;
        this->m = m;
        vector<vector<int>> ans(n,vector<int>(m,-1));
        ans[r][c] = 0;
        dfs(r,c,1,ans);
        return ans;
    }
};
