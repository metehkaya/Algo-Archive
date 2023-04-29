class Solution {
public:
    int minimumSwaps(vector<int>& v) {
        int n = v.size();
        int min_val = INT_MAX , max_val = INT_MIN , min_idx = -1 , max_idx = -1;
        for( int i = 0 ; i < n ; i++ ) {
            if(v[i] < min_val) {
                min_val = v[i];
                min_idx = i;
            }
            if(v[i] >= max_val) {
                max_val = v[i];
                max_idx = i;
            }
        }
        return min_idx + (n-1-max_idx) - (min_idx > max_idx);
    }
};
