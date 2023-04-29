class Solution {
public:
    int minIncrementForUnique(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        sort(ar.begin(),ar.end());
        for( int i = 1 ; i < n ; i++ ) {
            int val = max(ar[i-1]+1,ar[i]);
            ans += val-ar[i];
            ar[i] = val;
        }
        return ans;
    }
};