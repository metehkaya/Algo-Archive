class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        int mx = ar[n-1] - (n-1);
        for( int i = n-2 ; i >= 0 ; i-- ) {
            ans = max( ans , ar[i] + i + mx );
            mx = max( mx , ar[i] - i );
        }
        return ans;
    }
};