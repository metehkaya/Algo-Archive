class Solution {
public:
    int findClosestNumber(vector<int>& ar) {
        int n = ar.size();
        int best = INT_MAX;
        for( int i = 0 ; i < n ; i++ )
            if(abs(ar[i]) < abs(best) || (abs(ar[i]) == abs(best) && ar[i] > best))
                best = ar[i];
        return best;
    }
};
