class Solution {
public:
	const int MOD = 1000000007;
    int f(int id, int n, int k, string& s, vector<int>& dp) {
        if(id == n)
            return 1;
        if(dp[id] != -1)
            return dp[id];
        if(s[id] == '0')
            return dp[id] = 0;
        dp[id] = 0;
        long long val = 0;
        for( int i = id ; i < n ; i++ ) {
            val *= 10;
            val += s[i] - '0';
            if(val > k)
                break;
            dp[id] = ( dp[id] + f(i+1,n,k,s,dp) ) % MOD;
        }
        return dp[id];
    }
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<int> dp(n,-1);
        return f(0,n,k,s,dp);
    }
};