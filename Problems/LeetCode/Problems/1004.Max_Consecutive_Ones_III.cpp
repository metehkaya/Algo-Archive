class Solution {
public:
    int longestOnes(vector<int>& ar, int k) {
        int n = ar.size();
        vector<int> sum(n+1);
        sum[0] = 0;
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1] + ar[i-1];
        int ans = 0;
        for( int i = 1 ; i <= n ; i++ ) {
            int l = i , r = n , last = i-1;
            while(l <= r) {
                int m = (l+r) >> 1;
                int len = m-i+1;
                int cnt1 = sum[m] - sum[i-1];
                int cnt0 = len - cnt1;
                if(cnt0 <= k)
                    last = m , l = m+1;
                else
                    r = m-1;
            }
            ans = max(ans,last-i+1);
        }
        return ans;
    }
};