class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.length() , ans = 0;
        set<char> st({'a','e','i','o','u'});
        int dp[n+1][2];
        memset(dp,0,sizeof(dp));
        vector<int> mult;
        for( int i = 1 ; i <= n ; i++ ) {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            if(st.count(s[i-1]))
                dp[i][0]++;
            else
                dp[i][1]++;
            for( int j = 0 ; j < i ; j++ ) {
                int d0 = dp[i][0] - dp[j][0];
                int d1 = dp[i][1] - dp[j][1];
                if(d0 == d1 and d0*d1 % k == 0)
                    ans++;
            }
        }
        return ans;
    }
};
