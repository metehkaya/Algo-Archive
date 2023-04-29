class Solution {
public:
    int n;
    int sum[101];
    double dp[101][101];
    bool mark[101][101];
    double f(int id , int rem) {
        if(id == n)
            return 0;
        if(rem == 1)
            return (double)(sum[n]-sum[id]) / (double)(n-id);
        if(mark[id][rem])
            return dp[id][rem];
        mark[id][rem] = true;
        dp[id][rem] = (double)(sum[n]-sum[id]) / (double)(n-id);
        for( int i = id+1 ; i < n ; i++ ) {
            double val1 = (double)(sum[i]-sum[id]) / (double)(i-id);
            double val2 = f(i,rem-1);
            dp[id][rem] = max(dp[id][rem],val1+val2);
        }
        return dp[id][rem];
    }
    double largestSumOfAverages(vector<int>& ar, int k) {
        n = ar.size();
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1] + ar[i-1];
        return f(0,k);
    }
};