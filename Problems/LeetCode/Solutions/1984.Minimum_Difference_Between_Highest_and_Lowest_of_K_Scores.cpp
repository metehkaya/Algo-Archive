class Solution {
public:
    int minimumDifference(vector<int>& ar, int k) {
        int n = ar.size() , ans = INT_MAX;
        sort(ar.begin(),ar.end());
        for( int i = 0 ; i <= n-k ; i++ )
            ans = min(ans,ar[i+k-1]-ar[i]);
        return ans;
    }
};