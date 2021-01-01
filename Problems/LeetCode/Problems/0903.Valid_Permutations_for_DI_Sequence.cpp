class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    int numPermsDISequence(string s) {
        int n = s.length()+1;
        vector<int> sum(n+1,0);
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        dp[1][1] = sum[1] = 1;
        for( int i = 2 ; i <= n ; i++ ) {
            if(s[i-2] == 'D')
                for( int j = 2 ; j <= i ; j++ )
                    dp[i][j] = sum[j-1];
            else
                for( int j = 1 ; j < i ; j++ )
                    dp[i][j] = (sum[i-1] - sum[j-1] + MOD) % MOD;
            for( int j = 1 ; j <= i ; j++ )
                sum[j] = ( sum[j-1] + dp[i][j] ) % MOD;
        }
        return sum[n];
    }
};