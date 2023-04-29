class Solution {
public:
    bool increasingTriplet(vector<int>& ar) {
        int n = ar.size();
        int mn1 = INT_MAX , mn2 = INT_MAX;
        for( int i = 0 ; i < n ; i++ ) {
            if(ar[i] <= mn1)
                mn1 = ar[i];
            else if(ar[i] <= mn2)
                mn2 = ar[i];
            else
                return true;
        }
        return false;
    }
};