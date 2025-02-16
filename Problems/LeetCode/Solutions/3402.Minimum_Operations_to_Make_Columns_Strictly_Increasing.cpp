class Solution {
public:
    int minimumOperations(vector<vector<int>>& v) {
        int n = v.size() , m = v[0].size() , ans = 0;
        for( int j = 0 ; j < m ; j++ ) {
            for( int i = 1 ; i < n ; i++ ) {
                if(v[i][j] > v[i-1][j])
                    continue;
                int diff = v[i-1][j] + 1 - v[i][j];
                v[i][j] += diff;
                ans += diff;
            }
        }
        return ans;
    }
};