class Solution {
public:
    int n,m;
    string s,t;
    int dp[1000][1000];
    int f(int i , int j) {
        if(j == m)
            return 1;
        if(i == n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = 0;
        dp[i][j] = f(i+1,j);
        if(s[i] == t[j])
            dp[i][j] += f(i+1,j+1);
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;
        n = s.length();
        m = t.length();
        memset(dp,-1,sizeof(dp));
        return f(0,0);
    }
};