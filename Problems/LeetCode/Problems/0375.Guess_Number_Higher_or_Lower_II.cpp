class Solution {
public:
    int f(int l, int r, vector<vector<int>>& dp) {
        if(l >= r)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        for( int i = l ; i <= r ; i++ ) {
            int val = max( f(l,i-1,dp) , f(i+1,r,dp) ) + (i+1);
            if(dp[l][r] == -1 || val < dp[l][r])
                dp[l][r] = val;
        }
        return dp[l][r];
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return f(0,n-1,dp);
    }
};