class Solution {
public:
    int maximumDifference(vector<int>& ar) {
        int n = ar.size() , ans = -1;
        int mn = ar[0];
        for( int i = 1 ; i < n ; i++ ) {
            if(ar[i] > mn)
                ans = max(ans,ar[i]-mn);
            mn = min(mn,ar[i]);
        }
        return ans;
    }
};