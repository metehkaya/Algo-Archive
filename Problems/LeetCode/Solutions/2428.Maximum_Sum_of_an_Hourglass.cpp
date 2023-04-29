class Solution {
public:
    int maxSum(vector<vector<int>>& ar) {
        int n = ar.size() , m = ar[0].size() , ans = 0;
        for( int i = 0 ; i <= n-3 ; i++ )
            for( int j = 0 ; j <= m-3 ; j++ ) {
                int sum = ar[i+0][j+0] + ar[i+0][j+1] + ar[i+0][j+2] + ar[i+1][j+1] + ar[i+2][j+0] + ar[i+2][j+1] + ar[i+2][j+2];
                ans = max(ans,sum);
            }
        return ans;
    }
};
