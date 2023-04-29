class Solution {
public:
    int n;
    int sum[101];
    int findMiddleIndex(vector<int>& ar) {
        n = ar.size();
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1] + ar[i-1];
        for( int i = 1 ; i <= n ; i++ )
            if(sum[n]-sum[i] == sum[i-1])
                return i-1;
        return -1;
    }
};