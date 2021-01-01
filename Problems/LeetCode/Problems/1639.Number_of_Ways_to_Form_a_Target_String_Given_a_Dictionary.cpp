typedef long long LL;

class Solution {
public:
    const int mod = 1000000007;
    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int m = words[0].length();
        int k = target.length();
        int dp[m+1][k+1];
        memset(dp,0,sizeof(dp));
        int cnt[m][26];
        memset(cnt,0,sizeof(cnt));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                cnt[j][words[i][j]-'a']++;
        dp[0][0] = 1;
        for( int j = 0 ; j < m ; j++ )
            for( int i = 0 ; i < k ; i++ ) {
                dp[j+1][i] = (dp[j+1][i] + dp[j][i]) % mod;
                LL add2 = (LL) cnt[j][target[i]-'a'] * dp[j][i];
                int add = add2 % mod;
                dp[j+1][i+1] = (dp[j+1][i+1] + add) % mod;
            }
        int ans = 0;
        for( int i = k ; i <= m ; i++ )
            ans = (ans + dp[i][k]) % mod;
        return ans;
    }
};