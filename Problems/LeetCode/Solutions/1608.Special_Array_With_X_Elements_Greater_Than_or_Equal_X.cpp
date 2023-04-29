class Solution {
public:
    int sum[1001];
    int specialArray(vector<int>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            sum[ar[i]]++;
        for( int i = 1 ; i <= 1000 ; i++ )
            sum[i] += sum[i-1];
        int l = 0 , r = 1000 , last = -1;
        while(l <= r) {
            int m = (l+r) >> 1;
            int geq = (m == 0) ? n : n-sum[m-1];
            if(geq >= m)
                last = m , l = m+1;
            else
                r = m-1;
        }
        int geq = (last == 0) ? n : n-sum[last-1];
        return (last == geq) ? last : -1;
    }
};