class Solution {
public:
    static const int maxk = 50;
    static const int maxN = 50000;
    const int mod = (int)1e9 + 7;
    int n,m,k;
    int dp[maxN][maxk];
    int f(int r , int c , int s , vector<vector<int>>& grid) {
        if(r >= n || c >= m)
            return 0;
        s = (s+grid[r][c]) % k;
        if(r == n-1 && c == m-1)
            return (s == 0);
        int id = r*m+c;
        if(dp[id][s] != -1)
            return dp[id][s];
        dp[id][s] = (f(r,c+1,s,grid) + f(r+1,c,s,grid)) % mod;
        return dp[id][s];
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        this->k = k;
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,grid);
    }
};
