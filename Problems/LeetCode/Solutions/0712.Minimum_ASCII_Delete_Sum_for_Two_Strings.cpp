class Solution {
public:
    int n,m;
    string s,t;
    int dp[1001][1001];
    int f(int i , int j) {
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i == n && j == m)
            return dp[i][j] = 0;
        if(i == n)
            return dp[i][j] = f(i,j+1) + (int) t[j];
        if(j == m)
            return dp[i][j] = f(i+1,j) + (int) s[i];
        dp[i][j] = min( f(i,j+1) + (int) t[j] , f(i+1,j) + (int) s[i] );
        if(s[i] == t[j])
            dp[i][j] = min(dp[i][j],f(i+1,j+1));
        return dp[i][j];
    }
    int minimumDeleteSum(string s1, string s2) {
        s = s1 , t = s2;
        n = s.length();
        m = t.length();
        memset(dp,-1,sizeof(dp));
        return f(0,0);
    }
};