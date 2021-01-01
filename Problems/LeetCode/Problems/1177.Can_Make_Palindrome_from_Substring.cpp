class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(26,0));
        for( int i = 1 ; i <= n ; i++ ) {
            int c = s[i-1] - 'a';
            dp[i] = dp[i-1];
            dp[i][c]++;
        }
        vector<bool> ans;
        int m = q.size();
        for( int i = 0 ; i < m ; i++ ) {
            int l = q[i][0];
            int r = q[i][1] + 1;
            int k = q[i][2];
            int len = r - l;
            int odds = 0;
            for( int i = 0 ; i < 26 ; i++ )
                odds += (dp[r][i] - dp[l][i]) % 2;
            int cnt = (odds - len%2) / 2;
            ans.push_back(cnt <= k);
        }
        return ans;
    }
};