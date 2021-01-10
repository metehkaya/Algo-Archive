class Solution {
public:
    static const int maxn = 12;
    static const int maxN = (1<<maxn);
    int n,N;
    int sum[maxN];
    int dp[maxn+1][maxN];
    vector<int> can[maxN];
    int f(int bmask , int k) {
        if(k < 0)
            return INT_MAX;
        if(bmask == 0)
            return 0;
        if(dp[k][bmask] != -1)
            return dp[k][bmask];
        dp[k][bmask] = INT_MAX;
        int sz = can[bmask].size();
        for( int i = 0 ; i < sz ; i++ ) {
            int v = can[bmask][i];
            dp[k][bmask] = min( dp[k][bmask] , max( sum[v] , f(bmask^v,k-1) ) );
        }
        return dp[k][bmask];
    }
    int minimumTimeRequired(vector<int>& ar, int k) {
        n = ar.size();
        N = (1<<n);
        memset(dp,-1,sizeof(dp));
        for( int i = 0 ; i < N ; i++ ) {
            sum[i] = 0;
            for( int j = 0 ; j < n ; j++ )
                if((i&(1<<j)))
                    sum[i] += ar[j];
        }
        for( int i = 1 ; i < N ; i++ )
            for( int j = 1 ; j <= i ; j++ )
                if((i&j) == j)
                    can[i].push_back(j);
        return f(N-1,k);
    }
};