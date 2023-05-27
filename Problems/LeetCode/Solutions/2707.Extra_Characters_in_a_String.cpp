class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int> dp(n+1,0);
        for( int i = 0 ; i < n ; i++ ) {
            dp[i+1] = max(dp[i+1],dp[i]);
            for(string t : dictionary) {
                int len = t.length();
                if(i+len <= n and s.substr(i,len) == t)
                    dp[i+len] = max(dp[i+len],dp[i]+len);
            }
        }
        return n-dp[n];
    }
};
