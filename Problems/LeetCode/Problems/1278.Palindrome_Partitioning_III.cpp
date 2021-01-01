typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    int f(int curr , int rem , vii& cost , vii& dp , int n) {
        if(curr == n)
            return (rem == -1) ? 0 : INT_MAX;
        if(rem == 0)
            return cost[curr][n-1];
        if(dp[curr][rem] != -1)
            return dp[curr][rem];
        dp[curr][rem] = INT_MAX;
        for( int i = curr ; i < n ; i++ ) {
            int temp = f(i+1,rem-1,cost,dp,n);
            if(temp == INT_MAX)
                break;
            dp[curr][rem] = min( dp[curr][rem] , temp + cost[curr][i] );
        }
        return dp[curr][rem];
    }
    int palindromePartition(string s, int k) {
        int n = s.length();
        if(n == 1)
            return 0;
        vii cost(n,vi(n,0));
        for( int i = 0 ; i < n-1 ; i++ )
            cost[i][i+1] = (s[i] != s[i+1]);
        for( int len = 3 ; len <= n ; len++ )
            for( int i = 0 ; i <= n-len ; i++ ) {
                int j = i+len-1;
                cost[i][j] = cost[i+1][j-1] + (s[i] != s[j]);
            }
        vii dp(n,vi(k,-1));
        return f(0,k-1,cost,dp,n);
    }
};