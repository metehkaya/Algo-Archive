class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& ar) {
        int n = ar.size() , cnt = 0 , mn = INT_MAX;
        long long sum = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ ) {
                int absval = abs(ar[i][j]);
                sum += absval;
                mn = min(mn,absval);
                if(ar[i][j] < 0)
                    cnt++;
            }
        if(cnt % 2 == 0)
            return sum;
        else
            return sum-2*mn;
    }
};
