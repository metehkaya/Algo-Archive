class Solution {
public:
    int minMoves2(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        int idx = n/2;
        sort(ar.begin(),ar.end());
        for( int i = 0 ; i < n ; i++ )
            ans += abs(ar[i]-ar[idx]);
        return ans;
    }
};