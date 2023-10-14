class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxh) {
        int n = maxh.size();
        long long ans = 0;
        for( int k = 0 ; k < n ; k++ ) {
            vector<int> h(n);
            h[k] = maxh[k];
            for( int i = k-1 ; i >= 0 ; i-- )
                h[i] = min(h[i+1],maxh[i]);
            for( int i = k+1 ; i < n ; i++ )
                h[i] = min(h[i-1],maxh[i]);
            long long sum = 0;
            for(int x : h)
                sum += x;
            ans = max(ans,sum);
        }
        return ans;
    }
};
