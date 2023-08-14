class Solution {
public:
    static const int maxp5 = (1<<15);
    bool mark[maxp5];
    int minimumBeautifulSubstrings(string s) {
        int n = s.size();
        for( int i = 1 ; i < maxp5 ; i *= 5 )
            mark[i] = true;
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for( int i = 0 ; i < n ; i++ )
            if(dp[i] != INT_MAX and s[i] == '1')
                for( int j = i , val = 0 ; j < n ; j++ ) {
                    val = 2*val + (s[j]-'0');
                    if(mark[val])
                        dp[j+1] = min(dp[j+1],dp[i]+1);
                }
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};
