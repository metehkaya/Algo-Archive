class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n-1 ; i++ )
            ans += max( abs( ar[i][0] - ar[i+1][0] ) , abs( ar[i][1] - ar[i+1][1] ) );
        return ans;
    }
};