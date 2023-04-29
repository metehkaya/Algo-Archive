class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.length();
        vector<int> dp(n+1,-1);
        dp[n] = 0;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            long long num = 0;
            for( int j = i ; j < n and j < i+10 ; j++ ) {
                num = 10*num + (s[j]-'0');
                if(num <= k and dp[j+1] != -1) {
                    int val = dp[j+1]+1;
                    if(dp[i] == -1 or dp[i] > val)
                        dp[i] = val;
                }
            }
        }
        return dp[0];
    }
};
