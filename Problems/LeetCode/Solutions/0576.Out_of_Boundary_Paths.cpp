class Solution {
public:
    int n,m;
    int dp[50][50][51];
    const int mod = (int) 1e9+7;
    const int dir[4] = {0,1,0,-1};
    int dfs(int r , int c , int rem) {
        if(r < 0 || c < 0 || r >= n || c >= m)
            return 1;
        if(rem == 0)
            return 0;
        if(dp[r][c][rem] != -1)
            return dp[r][c][rem];
        dp[r][c][rem] = 0;
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r + dir[i];
            int y = c + dir[i^1];
            dp[r][c][rem] += dfs(x,y,rem-1);
            dp[r][c][rem] %= mod;
        }
        return dp[r][c][rem];
    }
    int findPaths(int m, int n, int mx, int r, int c) {
        this->m = n;
        this->n = m;
        memset(dp,-1,sizeof(dp));
        return dfs(r,c,mx);
    }
};