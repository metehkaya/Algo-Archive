class Solution {
public:
    const int DIR[4][2] = { {0,-1} , {-1,0} , {0,+1} , {+1,0} };
    int f(int r, int c, vector<vector<int>>& ar, vector<vector<int>>& dp) {
        if(dp[r][c] != -1)
            return dp[r][c];
        dp[r][c] = 0;
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r + DIR[i][0];
            int y = c + DIR[i][1];
            if(x < 0 || x >= ar.size() || y < 0 || y >= ar[0].size())
                continue;
            if(ar[x][y] <= ar[r][c])
                continue;
            dp[r][c] = max( dp[r][c] , f(x,y,ar,dp)+1 );
        }
        return dp[r][c];
    }
    int longestIncreasingPath(vector<vector<int>>& ar) {
        int n = ar.size();
        if(n == 0) return 0;
        int m = ar[0].size();
        if(m == 0) return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                ans = max( ans , f(i,j,ar,dp) );
        return ans+1;
    }
};