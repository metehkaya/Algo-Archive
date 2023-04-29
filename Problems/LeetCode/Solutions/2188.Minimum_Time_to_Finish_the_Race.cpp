typedef long long LL;

class Solution {
public:
    const LL lim = 1e9;
    const LL inf = (1LL<<50);
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int n) {
        vector<LL> add(31,lim);
        for( int i = 0 ; i < tires.size() ; i++ ) {
            int f = tires[i][0];
            int r = tires[i][1];
            LL curr = f , sum = 0;
            for( int j = 1 ; j < 31 ; j++ ) {
                sum += curr;
                if(sum >= lim)
                    break;
                add[j] = min(add[j],sum);
                curr *= r;
            }
        }
        vector<LL> dp(n+1,inf);
        dp[0] = 0;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= 30 && i-j >= 0 ; j++ )
                dp[i] = min(dp[i],dp[i-j]+add[j]+changeTime);
        return dp[n]-changeTime;
    }
};
