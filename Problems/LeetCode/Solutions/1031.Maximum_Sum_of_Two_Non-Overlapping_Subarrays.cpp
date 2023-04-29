class Solution {
public:
    int f(vector<int>& ar , vector<int>& sum , int n , int k1 , int k2) {
        vector<int> left(n,0);
        left[k1-1] = sum[k1];
        for( int i = k1 ; i < n ; i++ )
            left[i] = max( left[i-1] , sum[i+1] - sum[i+1-k1] );
        vector<int> right(n,0);
        right[n-k2] = sum[n] - sum[n-k2];
        for( int i = n-k2-1 ; i >= 0 ; i-- )
            right[i] = max( right[i+1] , sum[i+k2] - sum[i] );
        int ans = 0;
        for( int i = k1-1 ; i < n-k2 ; i++ )
            ans = max( ans , left[i] + right[i+1] );
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& ar, int k1, int k2) {
        int n = ar.size();
        if(k1+k2 > n)
            return 0;
        vector<int> sum(n+1,0);
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1] + ar[i-1];
        return max( f(ar,sum,n,k1,k2) , f(ar,sum,n,k2,k1) );
    }
};