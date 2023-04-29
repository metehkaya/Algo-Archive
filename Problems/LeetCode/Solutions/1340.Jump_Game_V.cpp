class Solution {
public:
    int f( int x , int d , vector<int>& ar , vector<int>& dp ) {
        if(dp[x])
            return dp[x];
        dp[x] = 1;
        int l = max( x-d , 0 );
        int r = min( x+d , (int) ar.size() - 1 );
        for( int i = x+1 ; i <= r ; i++ ) {
            if( ar[i] >= ar[x] )
                break;
            dp[x] = max( dp[x] , f(i,d,ar,dp) + 1 );
        }
        for( int i = x-1 ; i >= l ; i-- ) {
            if( ar[i] >= ar[x] )
                break;
            dp[x] = max( dp[x] , f(i,d,ar,dp) + 1 );
        }
        return dp[x];
    }
    int maxJumps(vector<int>& ar, int d) {
        int n = ar.size();
        vector<int> dp(n,0);
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            ans = max( ans , f(i,d,ar,dp) );
        return ans;
    }
};