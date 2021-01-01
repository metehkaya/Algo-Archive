class Solution {
public:
    const int MAXT = 101;
    int videoStitching(vector<vector<int>>& ar, int T) {
        vector<int> v(MAXT,-1);
        for( int i = 0 ; i < ar.size() ; i++ )
            v[ar[i][0]] = max( v[ar[i][0]] , ar[i][1] );
        vector<int> dp(MAXT,-1);
        dp[0] = 0;
        for( int i = 0 ; i < T ; i++ )
            if(dp[i] != -1 && v[i] != -1) {
                int k = v[i];
                for( int j = i+1 ; j <= k ; j++ )
                    if(dp[j] == -1 or dp[i]+1 < dp[j])
                        dp[j] = dp[i]+1;
            }
        return dp[T];
    }
};