class Solution {
public:
    const int mod = (int) 1e9+7;
    int numberOfCombinations(string s) {
        int n = s.length();
        vector<vector<int>> common(n+1,vector<int>(n+1,0));
        for( int i = n-1 ; i >= 0 ; i-- )
            for( int j = n-1 ; j >= 0 ; j-- )
                if(s[i] == s[j])
                    common[i][j] = common[i+1][j+1]+1;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<vector<int>> sum(n+1,vector<int>(n+1,0));
        for( int i = n-1 ; i >= 0 ; i-- ) {
            if(s[i] != '0') {
                for( int j = 1 ; j <= n ; j++ ) {
                    int idx = i+j;
                    if(idx < n and s[idx] != '0') {
                        int val = (sum[idx][n]-sum[idx][j]+mod) % mod;
                        int comm = common[i][idx];
                        if(comm >= j or (idx+comm < n and s[i+comm] < s[idx+comm]))
                            val = (val + dp[idx][j]) % mod;
                        dp[i][j] = val;
                    }
                    else if(idx == n)
                        dp[i][j] = 1;
                    sum[i][j] = (sum[i][j-1] + dp[i][j]) % mod;
                }
            }
        }
        return sum[0][n];
    }
};
