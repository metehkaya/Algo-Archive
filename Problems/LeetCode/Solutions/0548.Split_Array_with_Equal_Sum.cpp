class Solution {
public:
    bool splitArray(vector<int>& v) {
        int n = v.size();
        vector<int> sum(n);
        sum[0] = v[0];
        for( int i = 1 ; i < n ; i++ )
            sum[i] = sum[i-1]+v[i];
        int total = sum[n-1];
        for( int j = 3 ; j <= n-4 ; j++ ) {
            unordered_set<int> s;
            for( int i = 1 ; i <= j-2 ; i++ )
                if(sum[i-1] == sum[j-1]-sum[i])
                    s.insert(sum[i-1]);
            for( int k = j+2 ; k <= n-2 ; k++ )
                if(sum[k-1]-sum[j] == total-sum[k] and s.count(total-sum[k]))
                    return true;
        }
        return false;
    }
};
