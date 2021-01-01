typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    int prv(int x , int n) {
        return (x+n-1)%n;
    }
    int nxt(int x , int n) {
        return (x+1)%n;
    }
    int f(int s , int e , int n , vi& ar , vii& dp) {
        if(s == e or nxt(s,n) == e or nxt(e,n) == s)
            return 0;
        if(dp[s][e] != -1)
            return dp[s][e];
        dp[s][e] = INT_MAX;
        for( int i = nxt(s,n) ; i != e ; i = nxt(i,n) )
            dp[s][e] = min( dp[s][e] , f(s,i,n,ar,dp)+f(i,e,n,ar,dp) + ar[s]*ar[i]*ar[e] );
        return dp[s][e];
    }
    int minScoreTriangulation(vector<int>& ar) {
        int n = ar.size();
        int ans = INT_MAX;
        vii dp(n,vi(n,-1));
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                for( int k = j+1 ; k < n ; k++ )
                    ans = min( ans , f(i,j,n,ar,dp)+f(j,k,n,ar,dp)+f(k,i,n,ar,dp) + ar[i]*ar[j]*ar[k] );
        return ans;
    }
};