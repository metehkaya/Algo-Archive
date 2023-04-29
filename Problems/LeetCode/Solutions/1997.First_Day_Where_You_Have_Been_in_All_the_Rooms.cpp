class Solution {
public:
    const int mod = (int) 1e9+7;
    static const int maxn = 100003;
    int dp[maxn];
    int sum[maxn];
    int firstDayBeenInAllRooms(vector<int>& ar) {
        int n = ar.size();
        for( int i = 1 ; i < n ; i++ ) {
            dp[i] = (sum[i-1] - sum[ar[i-1]] + 2 + mod) % mod;
            sum[i] = (sum[i-1] + dp[i]) % mod;
        }
        return sum[n-1];
    }
};