class Solution {
public:
    int n;
    string s;
    int dp[1000][1000];
    int f(int i , int j) {
        if(i > j)
            return 0;
        if(i == j)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = max(f(i,j-1),f(i+1,j));
        if(s[i] == s[j])
            dp[i][j] = max(dp[i][j],f(i+1,j-1)+2);
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        this->s = s;
        n = s.length();
        memset(dp,-1,sizeof(dp));
        return f(0,n-1);
    }
};