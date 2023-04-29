class Solution {
public:
    int n;
    int sum[10001];
    int pivotIndex(vector<int>& ar) {
        int n = ar.size();
        sum[0] = 0;
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1] + ar[i-1];
        for( int i = 0 ; i < n ; i++ ) {
            int l = (i == 0) ? 0 : sum[i];
            int r = sum[n] - sum[i+1];
            if(l == r)
                return i;
        }
        return -1;
    }
};