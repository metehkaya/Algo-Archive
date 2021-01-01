class Solution {
public:
    static const int maxc = 27;
    static const int maxn = 250;
    int n;
    string s;
    int dp[maxn][maxn][maxc];
    int f(int l , int r , int k) {
        if(l >= r || l >= n || r < 0)
            return 0;
        if(dp[l][r][k] != -1)
            return dp[l][r][k];
        dp[l][r][k] = max(f(l+1,r,k),f(l,r-1,k));
        if(s[l] == s[r] && k != s[l]-'a'+1)
            dp[l][r][k] = max( dp[l][r][k] , f(l+1,r-1,s[l]-'a'+1)+2 );
        return dp[l][r][k];
    }
    int longestPalindromeSubseq(string s) {
        n = s.length();
        memset(dp,-1,sizeof(dp));
        this->s = s;
        return f(0,n-1,0);
    }
};