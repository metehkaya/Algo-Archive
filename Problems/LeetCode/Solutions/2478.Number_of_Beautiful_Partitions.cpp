const int MOD = (int) (1e9+7);

class Solution {
public:
    bool checkPrime(char c) {
        return (c=='2') or (c=='3') or (c=='5') or (c=='7');
    }
    int beautifulPartitions(string s, int k, int len) {
        int n = s.length();
        if(checkPrime(s[n-1]))
            return 0;
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        vector<int> cnt(k,0);
        dp[n][0] = 1;
        for( int i = n-len ; i >= 0 ; i-- ) {
            if(!checkPrime(s[i+len-1]))
                for( int j = 0 ; j < k ; j++ )
                    cnt[j] = (cnt[j] + dp[i+len][j]) % MOD;
            if(checkPrime(s[i]))
                for( int j = 0 ; j < k ; j++ )
                    dp[i][j+1] = cnt[j];
        }
        return dp[0][k];
    }
};
