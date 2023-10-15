class Solution {
public:
    vector<int> findIndices(vector<int>& v, int indexDifference, int valueDifference) {
        int n = v.size();
        for( int i = indexDifference ; i < n ; i++ )
            for( int j = 0 ; j <= i-indexDifference ; j++ )
                if(abs(v[i]-v[j]) >= valueDifference)
                    return {i,j};
        return {-1,-1};
    }
};
