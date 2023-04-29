typedef long long LL;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& ar) {
        int n = ar.size();
        LL dp[2] = {0,ar[0]};
        for( int i = 1 ; i < n ; i++ ) {
            int val = ar[i];
            LL x = dp[0] , y = dp[1];
            dp[1] = max(dp[1],x+val);
            dp[0] = max(dp[0],y-val);
        }
        return max(dp[0],dp[1]);
    }
};