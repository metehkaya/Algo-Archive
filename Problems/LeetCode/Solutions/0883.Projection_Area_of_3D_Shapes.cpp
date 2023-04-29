class Solution {
public:
    int projectionArea(vector<vector<int>>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                ans += (ar[i][j] > 0);
        for( int i = 0 ; i < n ; i++ ) {
            int mx = 0;
            for( int j = 0 ; j < n ; j++ )
                mx = max(mx,ar[i][j]);
            ans += mx;
        }
        for( int i = 0 ; i < n ; i++ ) {
            int mx = 0;
            for( int j = 0 ; j < n ; j++ )
                mx = max(mx,ar[j][i]);
            ans += mx;
        }
        return ans;
    }
};