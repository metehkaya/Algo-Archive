class Solution {
public:
    int minimumLines(vector<vector<int>>& p) {
        set<int> s_bmasks;
        int n = p.size();
        int N = (1<<n);
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ ) {
                int bmask = 0;
                int x1 = p[j][0]-p[i][0];
                int y1 = p[j][1]-p[i][1];
                for( int k = 0 ; k < n ; k++ ) {
                    int x2 = p[k][0]-p[i][0];
                    int y2 = p[k][1]-p[i][1];
                    if(x1*y2 == x2*y1)
                        bmask |= (1<<k);
                }
                s_bmasks.insert(bmask);
            }
        for( int i = 0 ; i < n ; i++ )
            s_bmasks.insert((1<<i));
        vector<int> bmasks(s_bmasks.begin(),s_bmasks.end());
        vector<int> dp(N,INT_MAX);
        dp[0] = 0;
        for( int bmask = 0 ; bmask < N ; bmask++ )
            if(dp[bmask] != INT_MAX)
                for(int val : bmasks) {
                    int bmask_new = (bmask | val);
                    dp[bmask_new] = min(dp[bmask_new],dp[bmask]+1);
                }
        return dp[N-1];
    }
};
