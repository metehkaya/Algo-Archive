typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    const int inv = INT_MIN + 1;
    int f(int i , int j , int n , vi& ar , vii& dp) {
        if(i >= n) {
            if(j)
                return inv;
            return 0;
        }
        if(dp[i][j] != INT_MIN)
            return dp[i][j];
        dp[i][j] = f(i+1,j,n,ar,dp);
        if(j) {
            int val = f(i+2,0,n,ar,dp);
            if(val != inv)
                dp[i][j] = max(dp[i][j],val+ar[i]);
        }
        else {
            int val = f(i+1,1,n,ar,dp);
            if(val != inv)
                dp[i][j] = max(dp[i][j],val-ar[i]);
        }
        return dp[i][j];
    }
    int maxProfit(vi& ar) {
        int n = ar.size();
        vii dp(n,vi(2,INT_MIN));
        return f(0,0,n,ar,dp);
    }
};