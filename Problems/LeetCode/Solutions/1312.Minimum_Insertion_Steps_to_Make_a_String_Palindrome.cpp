class Solution {
public:
    int f(int l, int r, vector<vector<int>> &dp, string &s) {
        if(l >= r)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        dp[l][r] = min( f(l+1,r,dp,s) , f(l,r-1,dp,s) ) + 1;
        if(s[l] == s[r])
            dp[l][r] = min( dp[l][r] , f(l+1,r-1,dp,s) );
        return dp[l][r];
    }
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return f(0,n-1,dp,s);
    }
};