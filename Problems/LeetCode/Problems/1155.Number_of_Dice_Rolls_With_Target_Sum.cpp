class Solution {
public:
    const int MOD = 1000000007;
    int numRollsToTarget(int d, int f, int target) {
        if(target > f*d || target < d)
            return 0;
        vector< vector<int> > dp(2, vector<int>(f*d+1));
        dp[0][0] = 1;
        for( int i = 1 ; i <= d ; i++ ) {
            bool oldRow = (i+1)%2;
            bool newRow = i%2;
            vector<int> add(i*f+2,0);
            for( int j = 0 ; j <= (i-1)*f ; j++ ) {
                add[j+1] = ( add[j+1] + dp[oldRow][j] ) % MOD;
                add[j+f+1] = ( add[j+f+1] - dp[oldRow][j] + MOD ) % MOD;
            }
            int sum = 0;
            for( int j = 0 ; j <= i*f ; j++ ) {
                sum = (sum + add[j]) % MOD;
                dp[newRow][j] = sum;
            }
        }
        return dp[d%2][target];
    }
};