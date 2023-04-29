class Solution {
public:
    int dp[16384];
    int sum[16384];
    int minSessions(vector<int>& ar, int maxt) {
        int n = ar.size();
        int N = (1 << n);
        for( int bmask = 1 ; bmask < N ; bmask++ )
            for( int i = 0 ; i < n ; i++ )
                if(bmask & (1<<i))
                    sum[bmask] += ar[i];
        for( int bmask = 1 ; bmask < N ; bmask++ ) {
            dp[bmask] = INT_MAX;
            for( int b = bmask ; b > 0 ; b = (b-1) & bmask )
                if(sum[b] <= maxt)
                    dp[bmask] = min(dp[bmask],dp[bmask-b]+1);
        }
        return dp[N-1];
    }
};