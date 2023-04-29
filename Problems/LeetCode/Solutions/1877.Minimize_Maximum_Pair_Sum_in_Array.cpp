class Solution {
public:
    int minPairSum(vector<int>& ar) {
        int n = ar.size();
        int ans = 0;
        sort(ar.begin(),ar.end());
        for( int i = 0 ; i < n/2 ; i++ )
            ans = max(ans,ar[i]+ar[n-1-i]);
        return ans;
    }
};