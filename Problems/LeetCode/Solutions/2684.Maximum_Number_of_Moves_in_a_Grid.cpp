class Solution {
public:
    int maxMoves(vector<vector<int>>& v) {
        int n = v.size() , m = v[0].size() , ans = 0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for( int j = m-2 ; j >= 0 ; j-- )
            for( int i = 0 ; i < n ; i++ ) {
                if(v[i][j] < v[i][j+1])
                    dp[i][j] = dp[i][j+1]+1;
                if(i-1 >= 0 and v[i][j] < v[i-1][j+1])
                    dp[i][j] = max(dp[i][j],dp[i-1][j+1]+1);
                if(i+1 < n and v[i][j] < v[i+1][j+1])
                    dp[i][j] = max(dp[i][j],dp[i+1][j+1]+1);
                if(j == 0)
                    ans = max(ans,dp[i][j]);
            }
        return ans;
    }
};
