class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<vector<int>> dp(n+1);
        dp[0].resize(26,0);
        for( int i = 1 ; i <= n ; i++ ) {
            dp[i] = dp[i-1];
            dp[i][s[i-1]-'a']++;
        }
        vector<int> ans;
        for(auto& q : queries) {
            int l = q[0] , r = q[1]+1 , sum = 0;
            for( int i = 0 ; i < 26 ; i++ ) {
                int k = dp[r][i] - dp[l][i];
                sum += k*(k+1)/2;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
