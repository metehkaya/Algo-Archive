#define mod 1000000007
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    int g(int s , int e , int f , vi& ar , vii& dp) {
        if(dp[s][f] != -1)
            return dp[s][f];
        dp[s][f] = (s == e);
        for( int i = 0 ; i < ar.size() ; i++ )
            if(s != i) {
                int x = abs(ar[i]-ar[s]);
                if(x <= f) {
                    dp[s][f] += g(i,e,f-x,ar,dp);
                    dp[s][f] %= mod;
                }
            }
        return dp[s][f];
    }
    int countRoutes(vi& ar, int start, int finish, int fuel) {
        int n = ar.size();
        vii dp(n,vi(fuel+1,-1));
        return g(start,finish,fuel,ar,dp);
    }
};