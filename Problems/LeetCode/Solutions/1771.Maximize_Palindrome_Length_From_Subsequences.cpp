class Solution {
public:
    int n,m;
    string S;
    int dp[2000][2000];
    int f(int l , int r) {
        if(l > r)
            return 0;
        if(l == r)
            return 1;
        if(dp[l][r] != -1)
            return dp[l][r];
        dp[l][r] = max(f(l+1,r),f(l,r-1));
        if(S[l] == S[r])
            dp[l][r] = max(dp[l][r],f(l+1,r-1)+2);
        return dp[l][r];
    }
    int longestPalindrome(string s, string t) {
        S = s+t;
        n = s.length();
        m = t.length();
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(s[i] == t[j])
                    ans = max(ans,f(i+1,n+j-1)+2);
        return ans;
    }
};