typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    int f(int i , bool can , int last , vii& dp , vi& ar) {
        if(i == last)
            return 0;
        if(dp[i][can] != -1)
            return dp[i][can];
        dp[i][can] = f(i+1,true,last,dp,ar);
        if(can)
            dp[i][can] = max(dp[i][can],f(i+1,false,last,dp,ar)+ar[i]);
        return dp[i][can];
    }
    int rob(vi& ar) {
        int n = ar.size();
        if(n == 1)
            return ar[0];
        vii dp(n,vi(2,-1));
        int res1 = f(1,false,n-1,dp,ar) + ar[0];
        dp.clear();
        dp.resize(n,vi(2,-1));
        int res2 = f(1,true,n,dp,ar);
        return max(res1,res2);
    }
};