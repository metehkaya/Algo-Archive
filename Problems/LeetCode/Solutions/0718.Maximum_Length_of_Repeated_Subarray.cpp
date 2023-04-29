class Solution {
public:
    int dp[1000][1000];
    int findLength(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        for( int i = 0 ; i < m ; i++ )
            dp[0][i] = (a[0] == b[i]);
        for( int i = 0 ; i < n ; i++ )
            dp[i][0] = (a[i] == b[0]);
        for( int i = 1 ; i < n ; i++ )
            for( int j = 1 ; j < m ; j++ )
                if(a[i] == b[j])
                    dp[i][j] = dp[i-1][j-1]+1;
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                ans = max(ans,dp[i][j]);
        return ans;
    }
};