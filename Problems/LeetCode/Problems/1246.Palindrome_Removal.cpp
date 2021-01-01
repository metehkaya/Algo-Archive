typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    int f(int l, int r, int n, vi& ar, vvi& dp) {
        if(l >= r)
            return 1;
        if(dp[l][r] != -1)
            return dp[l][r];
        dp[l][r] = r-l+1;
        if(ar[l] == ar[r])
            dp[l][r] = min( dp[l][r] , f(l+1,r-1,n,ar,dp) );
        for( int i = l ; i < r ; i++ )
            dp[l][r] = min( dp[l][r] , f(l,i,n,ar,dp) + f(i+1,r,n,ar,dp) );
        return dp[l][r];
    }
    int minimumMoves(vi& ar) {
        int n = ar.size();
        vvi dp(n,vi(n,-1));
        return f(0,n-1,n,ar,dp);
    }
};