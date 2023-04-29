class Solution {
public:
    int n,m;
    string s,t;
    int dp[100][100];
    int f(int i , int j) {
       if(j == m)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = INT_MAX;
        for( int k = 0 ; k < n ; k++ )
            if(s[k] == t[j]) {
                int cost = abs(i-k);
                cost = min(cost,n-cost)+1;
                dp[i][j] = min(dp[i][j],f(k,j+1)+cost);
            }
        return dp[i][j];
    }
    int findRotateSteps(string s, string t) {
        this->s = s;
        this->t = t;
        n = s.length();
        m = t.length();
        memset(dp,-1,sizeof(dp));
        return f(0,0);
    }
};
