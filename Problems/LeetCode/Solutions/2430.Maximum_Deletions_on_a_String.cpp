class Solution {
public:
    int deleteString(string s) {
        int n = s.length();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for( int i = n-2 ; i >= 0 ; i-- )
            for( int j = i+1 ; j < n ; j++ )
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j+1]+1;
        vector<int> ans(n,1);
        for( int i = n-2 ; i >= 0 ; i-- )
            for( int j = i+1 ; j < n ; j++ )
                if(dp[i][j] >= j-i)
                    ans[i] = max(ans[i],ans[j]+1);
        return ans[0];
    }
};
