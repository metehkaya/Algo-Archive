class Solution {
public:
    int minSwaps(vector<int>& ar) {
        int n = ar.size();
        vector<int> sum(n+1,0);
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1] + ar[i-1];
        int ans = INT_MAX , ones = sum[n];
        if(ones == 0)
            return 0;
        for( int i = 1 ; i <= n-ones+1 ; i++ )
            ans = min( ans , ones - sum[i+ones-1] + sum[i-1] );
        return ans;
    }
};