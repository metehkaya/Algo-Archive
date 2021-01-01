typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    int getCost(int l , int r , vi& ar , vi& sum) {
        int index = (l+r) / 2;
        int left = (index-l+1) * ar[index-1] - sum[index] + sum[l-1];
        int right = sum[r] - sum[index-1] - (r-index+1) * ar[index-1];
        return left+right;
    }
    int f(int n , int k , vi& ar , vi& sum , vii& dp) {
        if(n <= 1)
            return 0;
        if(dp[n][k] != -1)
            return dp[n][k];
        if(k == 1)
            return dp[n][k] = getCost(1,n,ar,sum);
        dp[n][k] = INT_MAX;
        for( int i = n-1 ; i >= 1 ; i-- )
            dp[n][k] = min(dp[n][k] , f(i,k-1,ar,sum,dp) + getCost(i+1,n,ar,sum));
        return dp[n][k];
    }
    int minDistance(vi& ar, int k) {
        sort(ar.begin(),ar.end());
        int n = ar.size();
        vi sum(n+1,0);
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1] + ar[i-1];
        vii dp(n+1,vi(k+1,-1));
        return f(n,k,ar,sum,dp);
    }
};