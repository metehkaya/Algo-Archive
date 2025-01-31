class Solution {
public:
    int minimumLevels(vector<int>& v) {
        int n = v.size();
        for( int i = 0 ; i < n ; i++ )
            if(v[i] == 0)
                v[i] = -1;
        vector<int> sum(n);
        sum[0] = v[0];
        for( int i = 1 ; i < n ; i++ )
            sum[i] = sum[i-1]+v[i];
        int total = sum[n-1];
        for( int i = 0 ; i < n-1 ; i++ )
            if(sum[i] > total-sum[i])
                return i+1;
        return -1;
    }
};
