class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        int ans = n;
        for( int i = 0 ; i < n ; i++ )
            ans = min(ans,ar[i]+(n-1)-i);
        return ans;
    }
};