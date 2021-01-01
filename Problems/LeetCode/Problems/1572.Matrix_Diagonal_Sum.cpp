class Solution {
public:
    int diagonalSum(vector<vector<int>>& ar) {
        int n = ar.size();
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            ans += ar[i][i] + ar[i][n-i-1];
        if(n&1)
            ans -= ar[n/2][n/2];
        return ans;
    }
};