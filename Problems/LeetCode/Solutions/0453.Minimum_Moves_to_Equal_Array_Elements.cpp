class Solution {
public:
    int minMoves(vector<int>& ar) {
        int n = ar.size() , minval = INT_MAX , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            minval = min(minval,ar[i]);
        for( int i = 0 ; i < n ; i++ )
            ans += ar[i]-minval;
        return ans;
    }
};