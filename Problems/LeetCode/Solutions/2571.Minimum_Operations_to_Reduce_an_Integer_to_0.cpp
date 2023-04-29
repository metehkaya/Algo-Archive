class Solution {
public:
    static const int maxb = 17;
    static const int maxs = (1<<maxb);
    int dp[maxs];
    int minOperations(int n) {
        queue<int> q;
        memset(dp,-1,sizeof(dp));
        q.push(0);
        dp[0] = 0;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for( int i = 0 ; i < 17 ; i++ )
                for( int mult = -1 ; mult <= 1 ; mult += 2 ) {
                    int y = x + mult*(1<<i);
                    if(y >= 0 and y < maxs and dp[y] == -1) {
                        dp[y] = dp[x]+1;
                        q.push(y);
                    }
                }
        }
        return dp[n];
    }
};
