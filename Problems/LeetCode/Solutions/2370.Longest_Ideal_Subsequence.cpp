class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length() , ans = 0;
        vector<int> dp(26,0);
        for( int i = 0 ; i < n ; i++ ) {
            int c = s[i]-'a';
            int mx = 0;
            for( int j = 0 ; j < 26 ; j++ )
                if(abs(c-j) <= k)
                    mx = max(mx,dp[j]);
            dp[c] = mx+1;
            ans = max(ans,dp[c]);
        }
        return ans;
    }
};
