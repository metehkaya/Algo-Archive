class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int m = robot.size();
        int n = factory.size();
        long long dp[n+1][m+1];
        for( int i = 0 ; i <= n ; i++ )
            for( int j = 0 ; j <= m ; j++ )
                dp[i][j] = LLONG_MAX;
        dp[0][0] = 0;
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j <= m ; j++ )
                if(dp[i][j] != LLONG_MAX) {
                    int mx = min(m-j, factory[i][1]);
                    long long cost = 0;
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j]+cost);
                    for( int k = 1 , idx = j ; k <= mx ; k++ , idx++ ) {
                        cost += abs(factory[i][0]-robot[idx]);
                        dp[i+1][idx+1] = min(dp[i+1][idx+1], dp[i][j]+cost);
                    }
                }
        return dp[n][m];
    }
};
