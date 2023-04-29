class Solution {
public:
    int maximumWealth(vector<vector<int>>& ar) {
        int n = ar.size() , m = ar[0].size() , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int sum = 0;
            for( int j = 0 ; j < m ; j++ )
                sum += ar[i][j];
            ans = max(ans,sum);
        }
        return ans;
    }
};