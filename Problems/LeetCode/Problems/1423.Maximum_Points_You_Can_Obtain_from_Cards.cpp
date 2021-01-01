class Solution {
public:
    int maxScore(vector<int>& ar, int k) {
        int n = ar.size();
        vector<int> sum(n+1,0);
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1] + ar[i-1];
        int ans = 0;
        for( int i = 0 ; i <= k ; i++ ) {
            int rem = k-i;
            ans = max( ans , sum[i] + ( sum[n] - sum[n-rem] ) );
        }
        return ans;
    }
};