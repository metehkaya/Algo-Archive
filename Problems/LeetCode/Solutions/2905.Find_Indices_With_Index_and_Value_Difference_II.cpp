class Solution {
public:
    vector<int> findIndices(vector<int>& v, int indexDifference, int valueDifference) {
        int n = v.size();
        int min_idx = -1 , min_val = INT_MAX;
        int max_idx = -1 , max_val = INT_MIN;
        for( int i = indexDifference ; i < n ; i++ ) {
            int j = i-indexDifference;
            if(v[j] < min_val) {
                min_val = v[j];
                min_idx = j;
            }
            if(v[j] > max_val) {
                max_val = v[j];
                max_idx = j;
            }
            if(abs(v[i]-min_val) >= valueDifference)
                return {min_idx,i};
            if(abs(v[i]-max_val) >= valueDifference)
                return {max_idx,i};
        }
        return {-1,-1};
    }
};
